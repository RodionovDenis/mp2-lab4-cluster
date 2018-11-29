#include "cluster.h"

TCluster::TCluster(vector<TProcessor> _processers, vector<TProgram> _allPrograms, TQueue<TProgram> _queue) : processers(_processers), allPrograms(_allPrograms), queue(_queue), unfulPrograms(_allPrograms) //конструктор
{
	stood = 0;
	coresCommon = 0;
	for (int i = 0; i < processers.size(); i++)
		coresCommon += processers[i].GetCores();
	coresCommonFree = coresCommon;
}

bool TCluster::IsCorrectedProgram(TProgram & program) //программа корректна для данного кластера?
{
	return program.GetCores() <= coresCommon && !queue.IsFull();
}

bool TCluster::DownloadProgram(TProgram & program) //загрузить программу в кластер
{
	for (int i = 0; i < processers.size(); i++)
		if (processers[i].ExProgram(program))
			return true;
	if (coresCommonFree >= program.GetCores())
	{
		coresCommonFree -= program.GetCores();
		return true;
	}
	return false;
}

void TCluster::GenPrograms(double threshould) //сгенерировать программу на одном такте
{
	for (int i = 0; i < unfulPrograms.size(); i++)
	{
		if (unfulPrograms[i].GenTask(threshould))
		{
			if (IsCorrectedProgram(unfulPrograms[i]))
				queue.Push(unfulPrograms[i]);
			else
				refusPrograms.push_back(unfulPrograms[i]);
			unfulPrograms.erase(unfulPrograms.begin() + i);
			i--;
		}
	}
	if (queue.IsEmpty() && unfulPrograms.size() != 0 && coresCommonFree != 0) //простои
		stood++;
}

void TCluster::PerformPrograms() //выполнить программы(один такт)
{
	for (int i = 0; i < queue.GetSize(); i++) //ставим на выполнение
	{
		if (DownloadProgram(queue.PopWithoutDelete()))
			runPrograms.push_back(queue.Pop());
		else break;
	}
	for (int i = 0; i < runPrograms.size(); i++) //есть ли выполненные?
	{
		if (runPrograms[i].GetLeftTacts() == 0)
		{
			readyPrograms.push_back(runPrograms[i]);
			coresCommonFree += runPrograms[i].GetCores();
			runPrograms.erase(runPrograms.begin() + i);
			i--;
		}
		else runPrograms[i].ChangeLeftTacts();
	}
}

void TCluster::RunTime(double threshould) //выполнить такт
{
	PerformPrograms();
	GenPrograms(threshould);
}

TStatistic TCluster::GetStatistic(int time) //получить статистику
{
	TStatistic statistic;
	statistic.numberPrograms = refusPrograms.size() + runPrograms.size() + readyPrograms.size();
	statistic.readyPrograms = readyPrograms.size();
	statistic.numberRefus = refusPrograms.size();
	statistic.numberTacts = (double)statistic.numberPrograms / time;
	statistic.stoodTacts = stood;
	return statistic;
}
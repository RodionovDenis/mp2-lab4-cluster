#include "cluster.h"

TCluster::TCluster(vector<TProcessor> _processers, vector<TProgram> _allPrograms, TQueue<TProgram> _queue) : processers(_processers), allPrograms(_allPrograms), queue(_queue), unfulPrograms(_allPrograms) //�����������
{
	stood = 0;
	coresCommon = 0;
	for (int i = 0; i < processers.size(); i++)
		coresCommon += processers[i].GetCores();
	coresCommonFree = coresCommon;
}

bool TCluster::IsCorrectedProgram(TProgram & program) //��������� ��������� ��� ������� ��������?
{
	return program.GetCores() <= coresCommon && !queue.IsFull();
}

bool TCluster::DownloadProgram(TProgram & program) //��������� ��������� � �������
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

void TCluster::GenPrograms(double threshould) //������������� ��������� �� ����� �����
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
	if (queue.IsEmpty() && unfulPrograms.size() != 0 && coresCommonFree != 0) //�������
		stood++;
}

void TCluster::PerformPrograms() //��������� ���������(���� ����)
{
	for (int i = 0; i < queue.GetSize(); i++) //������ �� ����������
	{
		if (DownloadProgram(queue.PopWithoutDelete()))
			runPrograms.push_back(queue.Pop());
		else break;
	}
	for (int i = 0; i < runPrograms.size(); i++) //���� �� �����������?
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

void TCluster::RunTime(double threshould) //��������� ����
{
	PerformPrograms();
	GenPrograms(threshould);
}

TStatistic TCluster::GetStatistic(int time) //�������� ����������
{
	TStatistic statistic;
	statistic.numberPrograms = refusPrograms.size() + runPrograms.size() + readyPrograms.size();
	statistic.readyPrograms = readyPrograms.size();
	statistic.numberRefus = refusPrograms.size();
	statistic.numberTacts = (double)statistic.numberPrograms / time;
	statistic.stoodTacts = stood;
	return statistic;
}
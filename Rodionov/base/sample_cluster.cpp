#include "cluster.h"
#include "clocale"
#include <random>
#include <Windows.h>


int TProgram::number = 0;

int main()
{
	setlocale(LC_ALL, "rus");
	int s, cores, time, tacts;
	double thr;
	char flag;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 1000);
	vector<TProgram> programs;
	vector<TProcessor> processors;
	TStatistic stat;
	cout << "Размер очереди программ" << endl;
	cout << "--> ";
	cin >> s;
	TQueue<TProgram> queue(s);
mark:	cout << "1. Сгенерировать программы." << endl;
	cout << "2. Сгенерировать процессоры кластера." << endl;
	cout << "3. Запустить кластер и рассчитать статистику." << endl;
	cout << "--> ";
	cin >> flag;
	switch (flag)
	{
	case '1':
	{
		int num = dis(gen);
		for (int i = 0; i < num; i++) //генерация программ
		{
			cores = dis(gen);
			time = dis(gen);
			TProgram prog(cores, time);
			programs.push_back(prog);
		}
		cout << "Сгенерировано " << num << " программ." << endl;
		goto mark;
	}
	case '2':
	{
		int num = dis(gen);
		for (int i = 0; i < num; i++) //генерация процессоров
		{
			cores = dis(gen);
			TProcessor proc(cores);
			processors.push_back(proc);
		}
		cout << "Сгенерировано " << num << " процессоров." << endl;
		goto mark;
	}
	case '3':
	{
		if (programs.size() == 0 || processors.size() == 0)
		{
			cout << "Сгенерируйте программы и процессоры, прежде чем запустить кластер." << endl;
			goto mark;
		}
		TCluster cluster(processors, programs, queue);
		cout << "Пороговое значение q (0<q<1) " << endl;
		cout << "--> ";
		cin >> thr;
		cout << "Количество тактов " << endl;
		cout << "--> ";
		cin >> tacts;
		for (int i = tacts; i != 0; i--)
			cluster.RunTime(thr);
		stat = cluster.GetStatistic(time);
		cout << "Количество поступивших программ: " << stat.numberPrograms << endl;
		cout << "Полностью выполненных программ: " << stat.readyPrograms << endl;
		cout << "Количество отказов: " << stat.numberRefus << endl;
		cout << "Среднее количество тактов выполнения заданий: " << stat.numberTacts << endl;
		cout << "Количество тактов простоя: " << stat.stoodTacts << endl;
	}
	}
}
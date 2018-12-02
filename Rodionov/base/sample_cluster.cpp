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
	cout << "������ ������� ��������" << endl;
	cout << "--> ";
	cin >> s;
	TQueue<TProgram> queue(s);
mark:	cout << "1. ������������� ���������." << endl;
	cout << "2. ������������� ���������� ��������." << endl;
	cout << "3. ��������� ������� � ���������� ����������." << endl;
	cout << "--> ";
	cin >> flag;
	switch (flag)
	{
	case '1':
	{
		int num = dis(gen);
		for (int i = 0; i < num; i++) //��������� ��������
		{
			cores = dis(gen);
			time = dis(gen);
			TProgram prog(cores, time);
			programs.push_back(prog);
		}
		cout << "������������� " << num << " ��������." << endl;
		goto mark;
	}
	case '2':
	{
		int num = dis(gen);
		for (int i = 0; i < num; i++) //��������� �����������
		{
			cores = dis(gen);
			TProcessor proc(cores);
			processors.push_back(proc);
		}
		cout << "������������� " << num << " �����������." << endl;
		goto mark;
	}
	case '3':
	{
		if (programs.size() == 0 || processors.size() == 0)
		{
			cout << "������������ ��������� � ����������, ������ ��� ��������� �������." << endl;
			goto mark;
		}
		TCluster cluster(processors, programs, queue);
		cout << "��������� �������� q (0<q<1) " << endl;
		cout << "--> ";
		cin >> thr;
		cout << "���������� ������ " << endl;
		cout << "--> ";
		cin >> tacts;
		for (int i = tacts; i != 0; i--)
			cluster.RunTime(thr);
		stat = cluster.GetStatistic(time);
		cout << "���������� ����������� ��������: " << stat.numberPrograms << endl;
		cout << "��������� ����������� ��������: " << stat.readyPrograms << endl;
		cout << "���������� �������: " << stat.numberRefus << endl;
		cout << "������� ���������� ������ ���������� �������: " << stat.numberTacts << endl;
		cout << "���������� ������ �������: " << stat.stoodTacts << endl;
	}
	}
}
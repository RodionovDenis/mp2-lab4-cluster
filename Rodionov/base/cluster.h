#define __CLUSTER_H__
#ifdef __CLUSTER_H__

#include "queue.h"
#include <vector>
#include "processor.h"

struct TStatistic
{
	int numberPrograms; //���������� ����������� ��������
	int readyPrograms; //��������� ����������� ��������
	int numberRefus; //���������� �������
	double numberTacts; //������� ���������� ������ ��������� �������
	int stoodTacts; //���������� ������ ������
};

class TCluster
{
	vector<TProcessor> processers; //���������� � ��������
	vector<TProgram> allPrograms; //������������ ���������
	vector<TProgram> unfulPrograms; //���������, ������� ��� �� ����������
	vector<TProgram> refusPrograms; //���������� ���������
	vector<TProgram> runPrograms; //����������� ��������� � ������ ������
	vector<TProgram> readyPrograms; //�������, ����������� ���������
	TQueue<TProgram> queue; //������� ���������
	int coresCommon; //����� ���������� ���� ��������
	int coresCommonFree; //����� ���������� ��������� ���� ��������
	int stood; //�������

public:
	TCluster(vector<TProcessor> _processers, vector<TProgram> _allPrograms, TQueue<TProgram> _queue); //�����������
	bool IsCorrectedProgram(TProgram & program); //��������� ��������� �� ������� ��������?
	bool DownloadProgram(TProgram & program); //��������� ��������� � �������
	void GenPrograms(double threshould); //������������� ��������� �� ����� �����
	void PerformPrograms(); //��������� ���������(���� ����)
	void RunTime(double threshould); //��������� ����
	TStatistic GetStatistic(int time); //�������� ����������
};


#endif


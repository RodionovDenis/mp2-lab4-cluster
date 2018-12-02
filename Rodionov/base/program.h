#define __PROGRAM_H__
#ifdef __PROGRAM_H__

#include <iostream>
#include <iomanip>

using namespace std;

class TProgram
{
	static int number; //����� ���������� ��������
	int id; //������������� ���������
	int coresProg; //���������� ���� ��� ����������
	int tactsProg; //���������� ������ ��� ����������
	int leftTacts; //������� ������ �������� ��� ���������� ���������?

public:

	TProgram(int _coresProg, int _tactsProg); //�����������
	TProgram();
	int GetCores(); // ������ ���������� ���� 
	int GetLeftTacts(); //������ ���������� ���������� ������
	void ChangeLeftTacts(); //�������� ���-�� ���������� ������
	bool GenTask(double threshould); //������������� ������� (�������� - �����)
};

#endif


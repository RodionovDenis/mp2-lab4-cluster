#define __PROCESSOR_H__
#ifdef __PROCESSOR_H__

#include "program.h"

class TProcessor
{
	int coresCPU; // ���������� ���� ����������
	int coresFree; //���������� ��������� ���� �� ������������ �����
public:
	TProcessor(int _coresCPU); //�����������
	int GetCores(); //�������� ���-�� ����
	int GetCoresFree(); //�������� ���-�� ��������� ����
	bool IsFree(); // ��������� ��������?
	bool IsBusy(); //��������� �����?
	bool ExProgram(TProgram & program); //��������� ��������� �� ���������� � ������� ���������
};

#endif


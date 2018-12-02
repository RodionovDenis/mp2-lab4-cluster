#include "processor.h"

TProcessor::TProcessor(int _coresCPU) : coresCPU(_coresCPU), coresFree(_coresCPU) {} //�����������

int TProcessor::GetCoresFree() //�������� ���-�� ��������� ����
{
	return coresFree;
}

int TProcessor::GetCores() //�������� ���-�� ����
{
	return coresCPU;
}

bool TProcessor::IsFree() //��������� ��������?
{
	return coresFree == coresCPU;
}

bool TProcessor::IsBusy() //��������� �����?
{
	return coresFree == 0;
}

bool TProcessor::ExProgram(TProgram & program) //��������� ��������� �� ���������� � ������� ���������
{
	if (program.GetCores() > coresFree)
		return false;
	coresFree -= program.GetCores();
	return true;
}
#include "program.h"
#include <random>

TProgram::TProgram(int _coresProg, int _tactsProg) : coresProg(_coresProg), tactsProg(_tactsProg), leftTacts(_tactsProg) //�����������
{
	number++;
	id = number;
}

TProgram::TProgram() : coresProg(0), tactsProg(0) //�����������
{}

int TProgram::GetCores() //������ ���-�� ����
{
	return coresProg;
}

int TProgram::GetLeftTacts() //������ ���������� ���������� ������
{
	return leftTacts;
}

void TProgram::ChangeLeftTacts() //�������� ���-�� ���������� ������
{
	leftTacts--;
}

bool TProgram::GenTask(double threshould) //������������� ������� (�������� - �����)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	return (dis(gen) >= threshould) ? true : false;
}

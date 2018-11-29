#include "program.h"
#include <random>

TProgram::TProgram(int _coresProg, int _tactsProg) : coresProg(_coresProg), tactsProg(_tactsProg), leftTacts(_tactsProg) //конструктор
{
	number++;
	id = number;
}

TProgram::TProgram() : coresProg(0), tactsProg(0) //конструктор
{}

int TProgram::GetCores() //узнать кол-во ядер
{
	return coresProg;
}

int TProgram::GetLeftTacts() //узнать количество оставшихся тактов
{
	return leftTacts;
}

void TProgram::ChangeLeftTacts() //изменить кол-во оставшихся тактов
{
	leftTacts--;
}

bool TProgram::GenTask(double threshould) //сгенерировать задание (параметр - порог)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	return (dis(gen) >= threshould) ? true : false;
}

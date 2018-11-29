#include "processor.h"

TProcessor::TProcessor(int _coresCPU) : coresCPU(_coresCPU), coresFree(_coresCPU) {} //конструктор

int TProcessor::GetCoresFree() //получить кол-во свободных ядер
{
	return coresFree;
}

int TProcessor::GetCores() //получить кол-во ядер
{
	return coresCPU;
}

bool TProcessor::IsFree() //процессор свободен?
{
	return coresFree == coresCPU;
}

bool TProcessor::IsBusy() //процессор занят?
{
	return coresFree == 0;
}

bool TProcessor::ExProgram(TProgram & program) //поставить программу на исполнение в текущий процессор
{
	if (program.GetCores() > coresFree)
		return false;
	coresFree -= program.GetCores();
	return true;
}
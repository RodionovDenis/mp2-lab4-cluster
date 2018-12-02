#define __PROCESSOR_H__
#ifdef __PROCESSOR_H__

#include "program.h"

class TProcessor
{
	int coresCPU; // количество ядер процессора
	int coresFree; //количество свободных ядер на определенном такте
public:
	TProcessor(int _coresCPU); //конструктор
	int GetCores(); //получить кол-во ядер
	int GetCoresFree(); //получить кол-во свободных ядер
	bool IsFree(); // процессор свободен?
	bool IsBusy(); //процессор занят?
	bool ExProgram(TProgram & program); //поставить программу на исполнение в текущий процессор
};

#endif


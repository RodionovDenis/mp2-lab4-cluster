#define __PROGRAM_H__
#ifdef __PROGRAM_H__

#include <iostream>
#include <iomanip>

using namespace std;

class TProgram
{
	static int number; //общее количество программ
	int id; //идентификатор программы
	int coresProg; //количество ядер для выполнения
	int tactsProg; //количество тактов для выполнения
	int leftTacts; //сколько тактов осталось для завершения обработки?

public:

	TProgram(int _coresProg, int _tactsProg); //конструктор
	TProgram();
	int GetCores(); // узнать количество ядер 
	int GetLeftTacts(); //узнать количество оставшихся тактов
	void ChangeLeftTacts(); //изменить кол-во оставшихся тактов
	bool GenTask(double threshould); //сгенерировать задание (параметр - порог)
};

#endif


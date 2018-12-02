#define __CLUSTER_H__
#ifdef __CLUSTER_H__

#include "queue.h"
#include <vector>
#include "processor.h"

struct TStatistic
{
	int numberPrograms; //количество поступивших программ
	int readyPrograms; //полностью выполненных программ
	int numberRefus; //количество отказов
	double numberTacts; //среднее количество тактов выполнени¤ заданий
	int stoodTacts; //количество тактов просто¤
};

class TCluster
{
	vector<TProcessor> processers; //процессоры в кластере
	vector<TProgram> allPrograms; //всевозможные программы
	vector<TProgram> unfulPrograms; //программы, которые еще не выполн¤лись
	vector<TProgram> refusPrograms; //отказанные программы
	vector<TProgram> runPrograms; //выполн¤ющиес¤ программы в данный момент
	vector<TProgram> readyPrograms; //готовые, выполненные программы
	TQueue<TProgram> queue; //очередь выполнени¤
	int coresCommon; //общее количество ¤дер кластера
	int coresCommonFree; //общее количество свободных ¤дер кластера
	int stood; //простои

public:
	TCluster(vector<TProcessor> _processers, vector<TProgram> _allPrograms, TQueue<TProgram> _queue); //конструктор
	bool IsCorrectedProgram(TProgram & program); //программа корректна дл¤ данного кластера?
	bool DownloadProgram(TProgram & program); //загрузить программу в кластер
	void GenPrograms(double threshould); //сгенерировать программу на одном такте
	void PerformPrograms(); //выполнить программы(один такт)
	void RunTime(double threshould); //выполнить такт
	TStatistic GetStatistic(int time); //получить статистику
};


#endif


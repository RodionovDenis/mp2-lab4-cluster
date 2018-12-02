#define __QUEUE_H__
#ifdef __QUEUE_H__


const int MaxQueueSize = 1000;

//int sizeQueue = 10;

template<class T>
class TQueue
{
	int begin; //указывает на первый занятый элемент
	int end; //указывает на позицию, куда можно положить элемент
	int size; //размер очереди
	int count; //количество элементов в очереди на текущий момент
	T * pMem;
public:
	TQueue(int _size = MaxQueueSize); //конструктор
	~TQueue(); //деструктор
	TQueue(const TQueue<T> & queue); //конструктор копирования
	TQueue<T> & operator=(const TQueue<T> & queue); //оператор присваивания
	int GetSize();//получит размер
	bool IsEmpty();//проверка на пустоту
	bool IsFull(); //проверка на полноту
	T Pop(); //вернуть первый элемент и удалить его
	T PopWithoutDelete(); //просмотр первого элемента без удаления
	void Push(T v); //добавить элемент в очередь
};

template <class T>
TQueue<T>::TQueue(int _size = MaxQueueSize) //конструктор
{
	if (_size < 1 || _size > MaxQueueSize)
		throw "data is not correct";
	begin = -1;
	end = 0;
	size = _size;
	count = 0;
	pMem = new T[size];
}

template <class T>
TQueue<T>::~TQueue() //деструктор
{
	delete[] pMem;
}/*-------------------------------------------------------------------------*/

template <class T>
TQueue<T>::TQueue(const TQueue<T> & queue) //конструктор копирования
{
	begin = queue.begin;
	end = queue.end;
	size = queue.size;
	count = queue.count;
	pMem = new T[size];
	for (int i = 0; i < size; i++)
		pMem[i] = queue.pMem[i];
}/*-------------------------------------------------------------------------*/

template <class T>
TQueue<T> & TQueue<T>::operator=(const TQueue<T> & queue) //оператор присваивания
{
	if (this == &queue)
		return *this;
	if (size != queue.size)
	{
		size = queue.size;
		delete[] pMem;
		pMem = new T[size];
	}
	begin = queue.begin;
	end = queue.end;
	count = queue.count;
	for (int i = 0; i < size; i++)
		pMem[i] = queue.pMem[i];
	return *this;
}/*-------------------------------------------------------------------------*/

template <class T>
int TQueue<T>::GetSize() //проверка на пустоту
{
	return count;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TQueue<T>::IsEmpty() //проверка на пустоту
{
	return !count;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TQueue<T>::IsFull() //проверка на полноту
{
	return count == size;
}/*-------------------------------------------------------------------------*/

template <class T>
T TQueue<T>::Pop() //вернуть первый элемент и удалить его
{
	count--;
	int flag = begin + 1;
	begin++;
	return pMem[flag % size];
}/*-------------------------------------------------------------------------*/

template <class T>
T TQueue<T>::PopWithoutDelete() //просмотр первого элемента без удаления
{
	return pMem[(begin + 1) % size];
}/*-------------------------------------------------------------------------*/

template <class T>
void TQueue<T>::Push(T v) //добавить элемент в очередь
{
	count++;
	pMem[end] = v;
	end = (end + 1) % size;
}/*-------------------------------------------------------------------------*/

#endif 


#define __QUEUE_H__
#ifdef __QUEUE_H__


const int MaxQueueSize = 1000;

//int sizeQueue = 10;

template<class T>
class TQueue
{
	int begin; //��������� �� ������ ������� �������
	int end; //��������� �� �������, ���� ����� �������� �������
	int size; //������ �������
	int count; //���������� ��������� � ������� �� ������� ������
	T * pMem;
public:
	TQueue(int _size = MaxQueueSize); //�����������
	~TQueue(); //����������
	TQueue(const TQueue<T> & queue); //����������� �����������
	TQueue<T> & operator=(const TQueue<T> & queue); //�������� ������������
	int GetSize();//������� ������
	bool IsEmpty();//�������� �� �������
	bool IsFull(); //�������� �� �������
	T Pop(); //������� ������ ������� � ������� ���
	T PopWithoutDelete(); //�������� ������� �������� ��� ��������
	void Push(T v); //�������� ������� � �������
};

template <class T>
TQueue<T>::TQueue(int _size = MaxQueueSize) //�����������
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
TQueue<T>::~TQueue() //����������
{
	delete[] pMem;
}/*-------------------------------------------------------------------------*/

template <class T>
TQueue<T>::TQueue(const TQueue<T> & queue) //����������� �����������
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
TQueue<T> & TQueue<T>::operator=(const TQueue<T> & queue) //�������� ������������
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
int TQueue<T>::GetSize() //�������� �� �������
{
	return count;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TQueue<T>::IsEmpty() //�������� �� �������
{
	return !count;
}/*-------------------------------------------------------------------------*/

template <class T>
bool TQueue<T>::IsFull() //�������� �� �������
{
	return count == size;
}/*-------------------------------------------------------------------------*/

template <class T>
T TQueue<T>::Pop() //������� ������ ������� � ������� ���
{
	count--;
	int flag = begin + 1;
	begin++;
	return pMem[flag % size];
}/*-------------------------------------------------------------------------*/

template <class T>
T TQueue<T>::PopWithoutDelete() //�������� ������� �������� ��� ��������
{
	return pMem[(begin + 1) % size];
}/*-------------------------------------------------------------------------*/

template <class T>
void TQueue<T>::Push(T v) //�������� ������� � �������
{
	count++;
	pMem[end] = v;
	end = (end + 1) % size;
}/*-------------------------------------------------------------------------*/

#endif 


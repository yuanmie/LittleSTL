// Queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

template <typename T>
class Queue
{
public:
	Queue(){ Queue(10); }
	Queue(int number) :n(number+1){ S = new T[n]; head = tail =  0; }
	~Queue(){ delete[] S; };
	void enqueue(T t);
	void dequeue();
	T Top();
	bool empty();

private:
	//对面的容量
	int n;
	T* S;
	int head;
	int tail;
};

template <typename T>
void Queue<T>::enqueue(T t)
{
	
	if (head != ((tail+1)%n))
	{
		
		S[tail] = t;
		if (tail == n - 1)
			tail = 0;
		else
			tail++;
	}
	else
	{
		std::cout << "Queue is full, can't push!!!" << std::endl;
	}
}

template <typename T>
void Queue<T>::dequeue()
{
	if (!empty())
	{
		if (head == n - 1)
			head = 0;
		else
			++head;
	}
	else
	{
		std::cout << "Queue is empty, can't pop!!!" << std::endl;
	}
}

template <typename T>
T Queue<T>::Top()
{
	if (!empty())
	{
		return S[head];
	}
	else
	{
		std::cout << "Queue is empty!!!" << std::endl;
		return NULL;
	}

}

template <typename T>
bool Queue<T>::empty()
{
	return head == tail;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Queue<int> S(2);
	std::cout << "s is empty? :" << S.empty() << std::endl;
	S.enqueue(10);
	std::cout << "s is empty? :" << S.empty() << std::endl;
	S.enqueue(20);
	std::cout << "s is empty? :" << S.empty() << std::endl;
	
	S.enqueue(30);
	std::cout << "s is empty? :" << S.empty() << std::endl;
	S.dequeue();
	std::cout << "s is empty? :" << S.empty() << std::endl;
	return 0;
}


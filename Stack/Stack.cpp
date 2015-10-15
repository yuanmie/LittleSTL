// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

template <typename T>
class Stack
{
public:
	 Stack(){}
	 Stack(int n) :n(n){ S = new T[n]; top = -1; }
	 ~Stack(){ delete[] S; };
	 void push(T t);
	 void pop();
	 T Top();
	 bool empty();

private: 
	//ջ������
		int n;
		T* S;
		int top;
};

template <typename T>
void Stack<T>::push(T t)
{
	//���ջ���ˣ���ʾջ��
	if (top < n - 1)
	{
		top++;
		S[top] = t;
	}
	else
	{
		std::cout << "stack is full, can't push!!!" << std::endl;
	}
}

template <typename T>
void Stack<T>::pop()
{
	if (!empty())
	{
		top--;
	}
	else
	{
		std::cout << "stack is empty, can't pop!!!" << std::endl;
	}
}

template <typename T>
T Stack<T>::Top()
{
	if (!empty())
	{
		return S[top];
	}
	else
	{
		std::cout << "stack is empty!!!" << std::endl;
		return NULL;
	}

}

template <typename T>
bool Stack<T>::empty()
{
	return top == -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Stack<int> S(10);
	std::cout << "s is empty? :" << S.empty() << std::endl;
	S.push(10);
	std::cout << "s.top() is " << S.Top() << std::endl;
	std::cout << "s is empty? :" << S.empty() << std::endl;
	S.pop();
	std::cout << "s is empty? :" << S.empty() << std::endl;
	return 0;
}


// ConsoleApplication7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define INIT_SIZE 10
#define INC_SIZE 10

class SeqStack
{
public:
	SeqStack()
	{
		m_capacity = INIT_SIZE;
		m_data = new int[m_capacity];
		m_top = 0;
	}
	~SeqStack()
	{
		if (m_data != NULL)
		{
			delete[]m_data;
			m_data = NULL;
		}
	}
	bool Inc();
	void Push(int v);
	void Pop();
	bool IsEmpty()const { return m_top == 0 ? true : false; }
	bool IsFull()const { return m_top == m_capacity ? true : false; }
	bool GetTop(int *value);
	void Print();
	void Clear();
	int size()const { return m_top; }
private:
	int *m_data;
	int m_capacity;
	int m_top;
};
bool SeqStack::Inc()
{
	int *temp = new int[m_capacity];
	int size = m_capacity;
	/*for(int i = 0;i<m_capacity;i++)
	temp[i] = m_data[i];
	*/
	memcpy(temp, m_data, sizeof(int)*m_capacity);
	m_capacity = m_capacity + INC_SIZE;
	delete[]m_data;
	m_data = new int[m_capacity];
	memcpy(m_data, temp, sizeof(int)*size);
	delete[]temp;
	temp = NULL;
	return true;
}
bool SeqStack::GetTop(int *value)
{
	if (IsEmpty())
		return false;
	else
		*value = m_data[m_top - 1];
}
void SeqStack::Print()
{
	for (int i = m_top - 1; i >= 0; i--)
		cout << m_data[i] << " ";
	cout << endl;
}
void SeqStack::Push(int v)
{
	if (!IsFull() || Inc())
		m_data[m_top++] = v;
}
void SeqStack::Pop()
{
	if (!IsEmpty())
		m_top--;
}

int main()
{
	SeqStack ss;
	int value;
	int i;
	for (i = 0; i < 10; i++)
		ss.Push(i);
	ss.Print();
	if (ss.GetTop(&value))
		cout << "top = " << value << endl;
	cout << ss.size() << endl;
	for (i = 10; i < 21; i++)
		ss.Push(i);
	ss.Print();
}

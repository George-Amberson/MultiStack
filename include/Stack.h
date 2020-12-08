#pragma once
#include <iostream>
#include <exception>

using namespace std; 


template<class A1>
class Stack
{
public:

	Stack()
	{
		data = nullptr;
		size = 0;
		DataCount = 0;
		top = 0;
		free_ceils = 0;
	}
	Stack(Stack& lhs):size(lhs.size),DataCount(lhs.DataCount),top(lhs.top),free_ceils(lhs.free_ceils)
	{
		data = new A1[lhs.size];
		for (int i = 0; i < lhs.size; i++)data[i] = lhs.data[i];

	}
	~Stack()
	{
		if(data!=nullptr)
		delete[] data;
	}
	bool is_empty()
	{
		return(DataCount == 0);
	}
	A1& pop(int index)
	{
		return data[index];
	}
	void set_top(int index)
	{
		top = index;
	}
	void inc_top()
	{
		top++;
	}
	void dec_top()
	{
		top--;
	}
	void inc_fc()
	{
		free_ceils++;
	}
	void dec_fc()
	{
		free_ceils--;
	}
	void set_fc(int index)
	{
		free_ceils = index;
	}
	int get_fc()
	{
		return(free_ceils);
	}
	void inc_Datacount()
	{
		DataCount++;
	}
	void dec_Datacount()
	{
		DataCount--;
	}
	void set_Datacount(int index)
	{
		DataCount = index;
	}
	int get_top()
	{
		return top;
	}
	int get_Datacount()
	{
		return DataCount;
	}
	void set_memory(int ceils_count)
	{
		data = new A1[ceils_count];
		size = ceils_count;

	}
private:
	A1* data;
	int size;
	int top;
	int DataCount;
	int free_ceils;
};
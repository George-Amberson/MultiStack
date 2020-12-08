#pragma once
#include <exception>
#include <algorithm>
#include "Stack.h"
using namespace std;


template<class A1>
class MultiStack
{
public:

	MultiStack(int _stackcount = 5, int stacksize = 10)
	{
		if ((_stackcount <= 0) || (stacksize <= 0)) throw logic_error("negative parametrs");
		Data = new Stack<A1>[_stackcount];
		for (int i = 0; i < _stackcount; i++) {
			Data[i].set_top(i*stacksize-1);
			Data[i].set_fc(stacksize);
			Data[i].set_memory(stacksize);
		}
		
		Datacount = 0;
		Size = _stackcount * stacksize;
		stack_count = _stackcount;
	}
	MultiStack(MultiStack& lhs) :Size(lhs.Size), Datacount(lhs.Datacount), stack_count(lhs.stack_count)
	{
		Data = new Stack<A1>[stack_count];
		for (int i = 0; i < stack_count; i++) 
		{
			Data[i].set_memory(lhs.Size / lhs.stack_count);
			Data[i].set_fc(lhs.Data[i].get_fc());
			Data[i].set_top(lhs.Data[i].get_top());
			Data[i].set_Datacount(lhs.Data[i].get_Datacount());
		}
		for (int i = 0; i < Size; i++)
		{
			(*this)[i] = lhs[i];
		}
	}
	~MultiStack() {
		delete[] Data;
	}
	bool is_full()
	{
		return(Datacount == Size);
	}
	bool is_full_stack(int stack_num)
	{
		if (stack_num + 1 < stack_count)
			return(Data[stack_num].get_top() == Data[stack_num + 1].get_top() - Data[stack_num + 1].get_Datacount());
		else
			return(Data[stack_num].get_top() == Size - 1);
	}
	bool is_empty()
	{
		return (Datacount == 0);
	}
	A1& operator [](int index)
	{
		return(Data[index / (Size / stack_count)].pop(index % (Size / stack_count)));
	}
	void push(const A1& lhs, int stacknum)
	{
		if (this->is_full()) throw logic_error("Multistack is full");
		if (this->is_full_stack(stacknum))
		{
			this->shift_all_left();
			this->reallocate(stacknum);
		}
		
			Data[stacknum].inc_top();
			(*this)[Data[stacknum].get_top()] = lhs;
			Data[stacknum].inc_Datacount();
			Data[stacknum].dec_fc();
			Datacount++;
			
	}
	A1& pop(int stacknum)
	{
		if (Data[stacknum].is_empty()) throw logic_error("stack is empty");
		A1 tmp = (*this)[Data[stacknum].get_top()];
		Data[stacknum].dec_top();
		Data[stacknum].dec_Datacount();
		Data[stacknum].inc_fc();
		Datacount--;
		return tmp;
	}
	int biggest_stack()
	{
		int stnum = 0;
		int dc = -1;
		for (int i = 0; i < stack_count; i++)
		{
			if (dc < Data[i].get_Datacount()) stnum = i;
		}
		return i;
	}
	void sort_stack()
	{
		int* ar = new int[stack_count];
		for (int i = 0; i < stack_count; i++) ar[i] = Data[i].get_Datacount();
		sort(ar, ar + stack_count);
		for (int i = 0; i < stack_count; i++) cout << ar[i] << " ";
		cout << endl;
	}
private:
	void shift_all_left()
	{
		for (int i = 1; i < stack_count; i++)
		{
			this->shift_on_count_ceils(Data[i - 1].get_fc(), i);
			for (int i = 0; i < Size; i++)
			{
				cout << (*this)[i] << " ";
			}
			cout << endl << endl;
		}
		
	}
	void shift_on_count_ceils(int count, int stack_num)
	{
		Data[stack_num - 1].set_fc(0);
		
		Data[stack_num].set_fc(Data[stack_num].get_fc() + count);
		for (int i = Data[stack_num].get_top() - Data[stack_num].get_Datacount()+1;
			i <= Data[stack_num].get_top(); i++)
		{
			(*this)[i - count] = (*this)[i];
			
		}
		Data[stack_num].set_top(Data[stack_num].get_top() - count);
		for (int i = 0; i < Size; i++)
		{
			cout << (*this)[i] << " ";
		}
		cout << endl << endl;
	}
	void shift_on_count_ceils_rigth(int count, int stack_num)
	{
		Data[stack_num - 1].set_fc( count);
		Data[stack_num].set_fc(Data[stack_num].get_fc() - count);
		for (int i = Data[stack_num].get_top();
			i >Data[stack_num].get_top()-Data[stack_num].get_Datacount(); i--)
		{
			(*this)[i+count] = (*this)[i];

		}
		Data[stack_num].set_top(Data[stack_num].get_top() + count);
	}
	void reallocate(int stack_num_w_w_p)
	{
		int fc = Data[stack_count - 1].get_fc();
		int fcfs = fc / stack_count;
		if (fcfs > 0)
		{
			for (int i = stack_count - 1; i > 0; i--)
			{
				shift_on_count_ceils_rigth(Data[i].get_fc() - fcfs, i);
			}
		}
			
		else
		{
				fcfs = fc % stack_count;
				for (int i = stack_count - 1; i > stack_num_w_w_p; i--)
				{
					shift_on_count_ceils_rigth(fcfs, i);
				}
		}
		
	}
	Stack<A1>* Data;
	int Datacount;
	int Size;
	int stack_count;
};


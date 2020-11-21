#pragma once
#include <exception>

using namespace std;
template<class A1>
struct LittleStack
{
	A1* ptr;
	int DataCount;
	int size;
	bool HasFreeMemory(int count)
	{
		return((size-DataCount)>count);
	}
};

template<class A1>
class MultiStack
{
public:
	MultiStack():Array(0),StacksStartIndex(0),StacksCount(0),CeilsCount(0),DataCount(0){}

	MultiStack(int _StackCount, int CeilCount)
	{
		Array = new A1[CeilCount];
		StacksCount = _StackCount;
		CeilsCount = CeilCount;
		stacs = new LittleStack<A1>[_StackCount];
		DataCount = 0;
		for (int i = 0; i < StacksCount; i++) stacs[i] = { Array + ((CeilsCount / StacksCount)*i),0,CeilsCount / StacksCount };
	}

	MultiStack(MultiStack& lhs)
	{
		Array = new A1[lhs.CeilCount];
		StacksCount = lhs.StackCount;
		CeilsCount = lhs.CeilsCount;
		stacs = new LittleStack<A1>[lhs.StackCount];
		DataCount = lhs.DataCount;
		for (int i = 0; i < lhs.StacksCount; i++)
		stacs[i] = { Array + ((CeilsCount / StacksCount)*i),0,CeilsCount / StacksCount };
		
	}
	~MultiStack()
	{
		if (Array != nullptr)
		{
			delete[] Array;
		}
		if (stacs != nullptr)
		{
			delete[] stacs;
		}
	}
	bool IsFull()
	{
		return(DataCount == StacksCount);
	}
	bool IsEmpty()
	{
		return(DataCount == 0);
	}
	void push(A1& lhs, int StackNum)
	{
		if (this->IsFull()) throw logic_error("Container is full");
		if (stacs[StackNum].DataCount - stacs[StackNum].size != 0)
		{
			stacs[StackNum].ptr[DataCount] = lhs;
			stacs[StackNum].DataCount++;
			return;
		}
		int pushceil = (CeilsCount - DataCount) / StacksCount;
		for (int i = 0; i < StacksCount; i++)
		{
			if (stacs[i].HasFreeMemory(pushceil))
			{

			}
		}

	}
	
	A1& pop(int StackNum)
	{
		
	}
	void ShiftLeft(int index, int count)
	{
		for (int i = 0; i < count; i++)
		{
			for (auto k = stacs[index].ptr - 1; k < (stacs[index].ptr + stacs[index].size-1); k++)
			{
				(*k) = *(k + 1);
			}
			stacs[index].ptr = stacks.ptr - 1;
			stacs[index].size++;
		}
	}
	void ShiftRight(int index, int count)
	{
		for (int i = 0; i < count; i++)
		{
			for (auto j = stacs[index].ptr + stacs[index].size; j > stacs[index].ptr; j--)
			{
				*(j) = *(j - 1);
			}
			stacs[index].ptr++;
			stacs[index].size--;
		}
		
	}
private:
	A1* Array;
	int StacksCount;
	LittleStack<A1>* stacs;
	int CeilsCount;
	int DataCount;
};


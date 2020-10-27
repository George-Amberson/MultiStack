#pragma once
#include <exception>

using namespace std;

struct LittleStack
{
	int first;
	int last;
};
template<class A1>
class MultiStack
{
public:
	MultiStack()
	{
		Array = nullptr;
		StacksCount = 0;
		StacksStartIndex = nullptr;
		CeilsCount = 0;
		DataCount = 0;
	}
	MultiStack(int _StackCount, int CeilCount)
	{
		if (_StackCount > CeilCount) throw logic_error("incorrect parametr");
		if ((_StackCount <= 0) || (CeilCount <= 0)) throw logic_error("Incorect parametrs");
		Array = new A1[CeilCount];
		CeilsCount = CeilCount;
		StacksCount = _StackCount;
		StacksStartIndex = new LittleStack[_StackCount];
		for (int i = 0; i < StacksCount; i++) StacksStartIndex[i] = { 0,0 };
		DataCount = 0;
	}

	MultiStack(MultiStack& lhs)
	{

		Array = new A1[lhs.CeilsCount];
		CeilsCount = lhs.CeilsCount;
		for (int i = 0; i < lhs.CeilsCount; i++)Array[i] = lhs.Array[i];
		StacksStartIndex = new LittleStack[lhs.StacksCount];
		StacksCount = lhs.StacksCount;
		for (int i = 0; i < lhs.StacksCount; i++) {
			StacksStartIndex[i] = lhs.StacksStartIndex[i];
		}
		DataCount = lhs.DataCount;
	}
	~MultiStack()
	{
		if (Array != nullptr)
		{
			delete[] Array;
		}
		if (StacksStartIndex != nullptr)
		{
			delete[] StacksStartIndex;
		}
	}
	bool IsFull()
	{
		return(DataCount == CeilsCount);
	}
	bool IsEmpty()
	{
		return (DataCount == 0);
	}
	void push(A1& lhs, int StackNum)
	{
		if ((*this).IsFull()) throw logic_error("MultiStack is Full");
		(*this).Shift(StackNum+1);
		Array[StacksStartIndex[StackNum].last] = lhs;
		StacksStartIndex[StackNum].last++;
		DataCount++;
	}
	
	A1& pop(int StackNum)
	{
		if ((*this).IsEmpty()) throw logic_error("Multistack is empty");
		if ((StacksStartIndex[StackNum].last - 1) < 0) throw logic_error("Stack is empty");
		StacksStartIndex[StackNum].last--;
		DataCount--;
		return(Array[StacksStartIndex[StackNum].last]);
	}
private:
	void Shift(int index)
	{
		for (int i = StacksCount - 1; i >= index; i--)
		{
			for (int j = StacksStartIndex[i].last; j > StacksStartIndex[i].first; j--)
			{
				Array[j] = Array[j - 1];
			}
			StacksStartIndex[i].last++;
			StacksStartIndex[i].first++;
		}
	}
	A1* Array;
	int StacksCount;
	LittleStack* StacksStartIndex;
	int CeilsCount;
	int DataCount;

};
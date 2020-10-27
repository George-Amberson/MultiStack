
#include <iomanip>
#include "MultiStack.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	MultiStack<int>A(3, 10);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			A.push(j, i);
		}
	}
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum+=A.pop(i);
		}
	}
	cout << sum;
	return 0;
	
}


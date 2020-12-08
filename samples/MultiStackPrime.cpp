
#include <iomanip>
#include "MultiStack.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	MultiStack<int>A(2, 3);
	
	A.push(1, 0);
	A.push(2, 0);
	A.push(5, 0);
	A.push(7, 1);
	A.push(3, 1);
	
	A.push(10, 0);
	cout<<A.pop(0);
	cout<<A.pop(0);
	cout<<A.pop(0);
	cout<<A.pop(0);
	cout<<A.pop(1);
	cout<<A.pop(1);
	//cout << A.pop(0);
}


#include <iostream>
#include "CList.h"
#include "CVector.h"
using namespace std;


int main()
{
	CVector<int> cVec(10);

	for (int i = 0; i < cVec.size(); i++)
	{
		cout << cVec[i] << endl;
	}

	printf("size : %d\n", (int)cVec.size());
	printf("capacity : %d\n", (int)cVec.capacity());

	cout << "pop_back twice" << endl;

	cVec.pop_back();
	cVec.pop_back();

	for (int i = 0; i < cVec.size(); i++)
	{
		cout << cVec[i] << endl;
	}

	printf("size : %d\n", (int)cVec.size());
	printf("capacity : %d\n", (int)cVec.capacity());

	cout << "push_back several times" << endl;

	for (int i = 0; i < 200; i++)
	{
		cVec.push_back(i);
		cout << "push_back " << endl;
		printf("size : %d\n", (int)cVec.size());
		printf("capacity : %d\n", (int)cVec.capacity());
	}
	

}


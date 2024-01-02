#include <iostream>
#include "CList.h"
#include "CVector.h"
using namespace std;


int main()
{
	CVector<int> cVec(10, 1);

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

	cVec.insert(3, 9999);
	cVec.insert(7, 9999);

	cout << "remove" << endl;
	cVec.remove(7);
	cVec.remove(3);


	cout << "all - - - - - -" << endl;
	for (int i = 0; i < cVec.size(); i++)
	{
		cout << cVec[i] << endl;
	}
}


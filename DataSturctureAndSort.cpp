#include <iostream>
#include "CList.h"
#include "CVector.h"
using namespace std;


int main()
{
	CVector<int> cVec({ 5,9,2,3,1 });

	for (int i = 0; i < cVec.size(); i++)
	{
		cout << cVec[i] << endl;
	}

	printf("size : %d\n", (int)cVec.size());
	printf("capacity : %d\n", (int)cVec.capacity());

}


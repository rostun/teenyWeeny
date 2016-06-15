// testTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZ 8

vector<int> findMode(int array[], int size)
{
	vector<int> modeVector; //creating vector

	sort(array, array + size);

	int counter = 0;
	int max = 0;
	int number = array[0];
	int mode = number;

	for (int i = 0; i < size; i++)
	{
		if (array[i] == number)                     
		{
			cout << counter << endl;
			counter++;
		}
		if (array[i] != number || i == size - 1) 
		{
			if (counter == max) 
			{
				mode = number;

				modeVector.push_back(mode); 

			}
			else if (counter > max)
			{
				max = counter;
				mode = number;

				modeVector.clear();
				modeVector.push_back(mode); 
			}
			if (array[i] != number && max == 1 && i == size - 1) //
			{
				modeVector.push_back(array[i]);
			}
			
			counter = 1; 
			number = array[i];
		}
	}


	sort(modeVector.begin(), modeVector.end());

	return modeVector;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int testArray[SIZ] = {1, 2, 3}; //array declared

	vector<int> testVector; //vector creating
	testVector = findMode(testArray, SIZ); //calling function

	for (int i = 0; i < testVector.size(); i++){
		cout << testVector[i];
	}
	cout << endl;
	return 0;
}


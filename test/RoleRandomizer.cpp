// RoleRandomizer.cpp : main project file.

#include "stdafx.h"

#include <iostream>
#include <cstdlib> //rand+srand
#include <time.h> //time
#include <stdio.h> //null
#include <string>

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	srand(time(NULL)); //seed
	
	string roles[5] = { "top", "mid", "adc", "support", "jungle" }; /*roles*/
	string summonerNames[5]; /*names*/

	cout << "Roll for your roll! :3 \n" << endl;
	char ans;

	for (int i = 0; i < 5; i++) /*get names*/
	{
		cout << "Enter summoner name " << i + 1 << ": ";
		getline(cin, summonerNames[i]);
	}

	do
	{
		// Randomize the array of roles.
		for (int i = 0; i < 5; ++i) 
		{
			std::swap(roles[i], roles[(rand() % (5 - i)) + i]);
		}
		
		for (int place = 0; place < 5; place++) /*output results*/
		{
			cout << summonerNames[place] << ": " << roles[place] << endl;
		}

		cout << "generate again? y or n " << endl;
		cin >> ans;
	} while (ans == 'y'); /*regenerate*/

	return 0;
}



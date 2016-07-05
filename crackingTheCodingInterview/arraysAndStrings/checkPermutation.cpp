/*
	Cracking the Coding Interview
	1.2 Check Permutation
		Given two strings, write a method to decide if one is a permutation of the other
*/


#include <iostream>
#include <map>
#include <string> 

using namespace std;

int main() {
    string firstString;
	string secondString;

	cin >> firstString >> secondString;

	//check size first
	if(firstString.size() != secondString.size()){
		cout << "NO" << endl;
	} else {
		//map <string, char> grade_list;
		//grade_list["John"] = 'B';
		map <int, int> firstChart; //character, tally
		map <int, int> secondChart;
		//set all tallies to 0
		for(int i = 0; i < 128; i++){
			firstChart[i] = 0;
			secondChart[i] = 0;
		}

		//tally up first word and second words
		for(int i = 0; i < firstString.size(); i++){
			firstChart[(int)firstString[i]]++;
			secondChart[(int)secondString[i]]++;
		}
	
		//check for same tally
		int letter = 0;
		int flag = 0;
		while(flag == 0){
			if(firstChart[letter] != secondChart[letter]){
				cout << "NO" << endl;
				flag = 1;
			}
			letter++;
			if(letter == 128){
				cout << "YES" << endl;
				flag = 1;
			}
		}

	}

	cin.get();
	cin.get();
    return 0;
}
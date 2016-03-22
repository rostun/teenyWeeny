/*
	hash table using map container
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <map> //O(logn) for inserts and finds
#include <iostream> 
#include <unordered_map>
using namespace std;

void getHashValue(char key, int & value); //will just be the number of the character

int _tmain(int argc, _TCHAR* argv[])
{
	string word;
	int value;

	cout << "enter string" << endl;
	cin >> word;

	map<int, vector <char>> characterChart; //ascii value, boolean

	for(int i = 0; i<26; i++){
		vector<char> myVector;
		characterChart[i] =  myVector; //initialize all to unvisited
	}

	//can't have duplicate keys
	for(int i = 0; i<word.length(); i++){
		getHashValue(word[i], value);
		characterChart[value].push_back(word[i]);
	}
	
	cout << "map size: " << characterChart.size() << endl;

	for(auto it = characterChart.begin(); it != characterChart.end(); it++){ //same as old way
		cout << it->first << ": ";
		for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
			cout << *it2 << " ";
		}
		cout << endl;
	}
	
	return 0;
}

void getHashValue(char key, int & value){
	int asciiCode = (int)key; 
	if(asciiCode < 91 && asciiCode > 64){
		value = asciiCode-65; //65-65 = 0, 1, 2, 3, etc
	}
	if(asciiCode < 123 && asciiCode > 96){
		value = asciiCode-97; //97-97 = 0, 1, 2, 3, etc
	}
}
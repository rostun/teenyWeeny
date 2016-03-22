/*
	1. give ascii code of characters in a string
	2. see number of letters in string
	
	A-Z = 65-90
	a-z = 97-122
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <map> //O(logn) for inserts and finds
#include <iostream> 
using namespace std;


void getHashValue(char key, int & value); //will just be the number of the character

int _tmain(int argc, _TCHAR* argv[])
{
	string word;
	int value;

	cout << "enter string" << endl;
	cin >> word;

	map<char, int> characterTally;

	//can't have duplicate keys
	for(int i = 0; i<word.length(); i++){
		getHashValue(word[i], value);
		characterTally.insert(pair<char, int>(word[i], value));
	}
	
	cout << "map size: " << characterTally.size() << endl;

	for(std::map<char, int>::const_iterator it = characterTally.begin(); it != characterTally.end(); ++it){
		cout << it->first << " " << it->second << endl;
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

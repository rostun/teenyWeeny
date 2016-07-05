/*
	Cracking the Coding Interview 
	1.1 Is Unique
		Implement an algorithm to determine if a string has all unique characters.
		What if you can't use additional data structures?
*/

/*
	//another solution: do a quick-sort or merge sort in O(nlogn) time
	//then do a single pass over the sorted string to determine if there are any duplicates in O(N)

	#include<algorithm>
	string s = "dacb"
	sort(s.begin(), s.end()); //complexity of O(nlgn)
	
	for(int i = 0; i<s.length(); i++){
		if(s[i] == s[i+1]){
			
		}
	}
*/

//1. Implement an algorithm to determine if a string has all unique characters.
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

	map<int, int> characterChart; //ascii value, boolean

	for(int i = 0; i<26; i++){
		characterChart[i] = 1; //initialize all to unvisited
	}

	//can't have duplicate keys
	for(int i = 0; i<word.length(); i++){
		getHashValue(word[i], value);
		if(characterChart[value] == 0){
			cout << "repeating value" << endl;
			i = word.length()-1;
		}
		else{
			characterChart[value] = 0; //visited
		}
	}
	
	cout << "map size: " << characterChart.size() << endl;

	for(std::map<int, int>::const_iterator it = characterChart.begin(); it != characterChart.end(); ++it){
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

//2. What if you can't use additional data structures?
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream> 
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string word; 

	cout << "input a string" << endl;
	cin >> word;

	vector <string> characters;
	string character; 
	
	for(int i = 0; i<word.length(); i++){
		character = word[i];
		characters.push_back(character);
	}

	int flag = 0;

	while(characters.size() != 1){
		for(int i = 0; i<characters.size()-1; i++){
			if(characters[characters.size()-1] == characters[i]){ //always comparing the last character to the rest
				cout << "not unique" << endl; //without data structures, i would need an extra counter to keep track of the new length
				flag = 1;
			}
		}
		characters.pop_back(); //delete end
		cout << "pop!" << characters.size() << endl;
	}

	if(flag == 0){
		cout << "characters were unique" << endl;
	}
	return 0;
}
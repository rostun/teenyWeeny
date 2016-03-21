/*
	Cracking the Coding Interview: 1.1 Is Unique
		1. Implement an algorithm to determine if a string has all unique characters.
		2. What if you can't use additional data structures?
			to do it without data structure, i would need to instead copy over the word to another word
*/

/*
	//1.1 solution: make a boolean table to represent the charset
	//if it's been visited before, mark as visited
	//cout << typeid(word[0]).name() << endl; (include typeinfo)
	for(int i = 97; i<123; i++){
		cout << i << " " << (char)i << endl;
	}
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
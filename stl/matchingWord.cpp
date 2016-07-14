/*
	return matching words from two strings

	1. duplicates?
	2. what counts as a word (space, comma, etc)
	3. length of strings
	4. empty strings?

	assuming if something is separated by a space on either side, it's a "word"
		test cases for empty strings, no words, etc. left out
*/

#include <iostream>
#include <vector>
#include <string> 
#include <unordered_set>

using namespace std;

int main() {

	//const char LETTERS[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s( "This12 34is 56a78 test" );
	string ss( "This12 34is test" );

	//getline (cin, s);

	unordered_set <string> v;
	string word = "";

	for(int i = 0; i < s.size(); i++){
		if(s[i] != ' '){
			word = word + s[i];
		} else {
			v.insert(word);
			word = "";
		}
		//cout << word << endl;
	}
	v.insert(word);
	//cout << endl;

	/*for(int i = 0; i < v.bucket_count(); i++){
		cout << "bucket #" << i << " contains:";
		for(auto it = v.begin(i); it != v.end(i); it++){
			cout << " " << *it;
		}
		cout << endl;
	}*/

	vector <string> sameWords;
	unordered_set<string>::const_iterator got;
	word = "";

	for(int i = 0; i < ss.size(); i++){
		cout << "loop" << endl;
		if(ss[i] != ' '){
			word = word + ss[i];
		} 
		if(i == ss.size()-1 || ss[i] == ' '){
			cout << word << endl;
			//check if word is in bucket
			got = v.find(word);
			if(got != v.end()){
				cout << "matching" << endl;
				sameWords.push_back(*got);
			}
			word = "";
		}
	}

	for(int i = 0; i < sameWords.size(); i++){
		cout << sameWords[i] << endl;
	}

	cin.get();
    return 0;
}
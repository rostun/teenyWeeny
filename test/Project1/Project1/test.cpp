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
#include <string>
#include <stack>
#include <locale>

using namespace std;

int findMatchingPair(const string& input);

// Driver program to test methods of graph class
int main()
{
	string line = "XYZzxy";

    cout << "Index of Pair:  "
         << findMatchingPair(line);
    
	cin.get();
	return 0;
}

int findMatchingPair(const string& input){

	stack <char> container;
	int lastIndex = -1;

	int i = 0;
	char top;

	//go through the input, push things on to the stack 
	while(i < input.length()){
		if(container.empty()){
			container.push(input[i]);
			i++;
		}
		//cout << container.top() << " " << input[i] << endl;
		if(islower(input[i]) && isupper(container.top())){
			//see if top of container is uppercase version of input
			top = container.top();
			if(input[i] == tolower(top)){			
				container.pop();			
				lastIndex = i;
			} else {
				container.push(input[i]);
			}
		} else {
			container.push(input[i]);
		}
		i++;
	}
	
	return lastIndex;
}
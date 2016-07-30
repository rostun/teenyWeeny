//Given an array of integers, find two numbers such that 
//they add up to a specific target number 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void findPairs(vector <int> numbers, int k);

int main(){
	int num = 6;
	int k = 3;
	int arr[] = {1, 3, 4, 5, 6, 2};
	vector <int> numbers(arr, arr+num);
	
	findPairs(numbers, k);

	cin.get();
	return 0;
}

void findPairs(vector <int> numbers, int k){
	//put vector numbers into set
	map <int, int> hash;
	map <int, int>::iterator it;
	
	for(int i = 0; i < numbers.size(); i++){
		//key is number value is index
		hash.insert(make_pair(numbers[i], i)); 
	}
	//look for some pairs
	int complement;
	for(int i = 0; i < numbers.size(); i++){
		//looking for complement of number in hash table
		complement = k - numbers[i];
		it = hash.find(complement);
		//also make sure it doesn't have the index i
		//**no duplicate values**
		if(it != hash.end() && it->second != i){
			cout << "first number: " << numbers[i] << endl;
			cout << "second number: " << it->first << endl;
		}
	}
}
/*
	Given an array of integers, write a funciton to find the maximum product of any three unique numbers
	alternate solution **without sorting**
		pick out the top three positive numbers and lowest two negative numbers
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <functional> //greater

using namespace std;

void findProduct(vector <int> numbers);

int main()
{
	//{8, -20, 4, 9, 10, 4, 4, 2};
	//{-1, -1, -1};
	//{0};
	//{-1, 3, 3, 3};
	int arrayIntegers[] = {8, -20, 4, 9, -10, 4, 4, 2};
	int sizeArray = sizeof(arrayIntegers)/sizeof(arrayIntegers[0]);
	vector <int> numbers;

	for(int i = 0; i<sizeArray; i++){
		numbers.push_back(arrayIntegers[i]);
	}

	findProduct(numbers);
	//cout << "maxProduct: " << maxProduct << endl;
	cin.get();
	return 0;
}

void findProduct(vector<int> numbers){

	int maxProduct;
	vector <int> negativeNums;

	//3 or less numbers
	if(numbers.size() < 3){
		cout << "less than 3 numbers" << endl;
		return;
	}
	if(numbers.size() == 3){
		maxProduct = numbers[0]*numbers[1]*numbers[2];
		cout << "maxProduct: " << maxProduct << endl;
		return;
	}

	//sort numbers
	sort(numbers.begin(), numbers.end(), greater<int>());

	//get negative numbers if there are any
	int i = numbers.size()-1;
	while(numbers[i] < 0){
		negativeNums.push_back(numbers[i]);
		i--;
	}

	//testing both vectores
	for(int i = 0; i < negativeNums.size(); i++){cout << negativeNums[i] << endl;}
	for(int i = 0; i < numbers.size(); i++){cout << numbers[i] << endl;}

	//if not enough negative numbers to matter
	if(negativeNums.size() < 2){
		maxProduct = numbers[0]*numbers[1]*numbers[2];
	}
	//if we have a decent amount of both, see which is better
	else {
		int negPair = negativeNums[0]*negativeNums[1]*numbers[0];
		int posPair = numbers[0]*numbers[1]*numbers[2];
		if(negPair > posPair){
			maxProduct = negPair;
		} else {
			maxProduct = posPair;
		}
	}

	cout << "maxProduct: " << maxProduct << endl;
}
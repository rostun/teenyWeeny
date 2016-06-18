/*
	http://blog.codility.com/2011/03/solutions-for-task-equi.html
	A zero-indexed array A consisting of N integers is given. An equilibrium index of this array is any integer P such that 0 ≤ P < N and the sum of elements of lower indices is equal to the sum of elements of higher indices, i.e. 
	A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1].
	Sum of zero elements is assumed to be equal to 0. This can happen if P = 0 or if P = N−1.

	For example, consider the following array A consisting of N = 8 elements:

	  A[0] = -1
	  A[1] =  3
	  A[2] = -4
	  A[3] =  5
	  A[4] =  1
	  A[5] = -6
	  A[6] =  2
	  A[7] =  1
	P = 1 is an equilibrium index of this array, because:

	A[0] = −1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7]
	P = 3 is an equilibrium index of this array, because:

	A[0] + A[1] + A[2] = −2 = A[4] + A[5] + A[6] + A[7]
	P = 7 is also an equilibrium index, because:

	A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0
	and there are no elements with indices greater than 7.

	P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ≤ P < N.

	Write a function:

	int solution(vector<int> &A);

	that, given a zero-indexed array A consisting of N integers, returns any of its equilibrium indices. The function should return −1 if no equilibrium index exists.

	For example, given array A shown above, the function may return 1, 3 or 7, as explained above.

	Assume that:

	N is an integer within the range [0..100,000];
	each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
	Complexity:

	expected worst-case time complexity is O(N);
	expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
	Elements of input arrays can be modified.

	Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <functional> //greater

using namespace std;

int solution(vector <int> &A);

int main()
{
	//{8, -20, 4, 9, 10, 4, 4, 2};
	//{-1, -1, -1};
	//{0};
	//{-1, 3, 3, 3};
	int arrayIntegers[] = {-1, 3, -4, 5, 1, -6, 2, 1};
	int sizeArray = sizeof(arrayIntegers)/sizeof(arrayIntegers[0]);
	vector <int> numbers;
	int index;

	for(int i = 0; i<sizeArray; i++){
		numbers.push_back(arrayIntegers[i]);
	}

	index = solution(numbers);
	cout << "index: " << index << endl;
	cin.get();
	return 0;
}

int solution(vector<int> &A) {
    int equilIndex = -1;
    
    if(A.size() == 0){
        return -1;
    }
	if(A.size() == 1){
		if(A[0] == 0){
			return 0;
		} else {
			return -1;
		}
	}
    
    vector <int> right;   
    int testIndex = A.size()-1; //P = SIZE
    int currentValue;
    int sumLeft = 0;
    int sumRight = 0; //assuming sumRight starts off at 0
    
	//sum everything on the left
	for(unsigned int i = 0; i < A.size(); i++){
		sumLeft = sumLeft + A[i];
	} 	
	//test P = SIZE, SIZE-1, etc.
	while(A.size() != 0){
		//take out P, store the value as well, then pop off
		sumLeft = sumLeft - A.back();
		currentValue = A.back();
		A.pop_back();
		//test right and left sums
		if(sumLeft == sumRight){
			return testIndex;
		}
		sumRight = sumRight + currentValue;
		testIndex--;
    }
    
    return equilIndex;
}
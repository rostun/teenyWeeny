/*
	dynamic arrays
*/

#include "stdafx.h"
#include <iostream> 
using namespace std;

class anArray{
	private:
		int size;
		int capacity;
		int *container;
	public:
		anArray(){
			this->container = NULL;
			this->capacity = NULL;
			this->size = 0;
		}
		anArray(int capacity){
			this->container = new int[capacity];
			this->capacity = capacity;
			this->size = 0;
		}
		~anArray(){
			delete [] container;
		}
		void insertValue(int N){
			if(size<capacity){
				container[size] = N;
				size++;
			}
			else{
				cout << "full!" << endl;
				extendCapacity(N);
			}
		}
		void extendCapacity(int N){
			int* placeholder = new int[capacity];
			for(int i = 0; i<capacity; i++){
				placeholder[i] = container[i];
				cout << "copying" << endl;
			}
			container = new int[capacity*2];
			for(int i = 0; i<capacity; i++){
				container[i] = placeholder[i];
				cout << "reallocating" << endl;
			}
			container[size] = N;
			capacity = capacity*2;
			size++;
		}
		int getSize(){
			return size;
		}
		int getCapacity(){
			return capacity;
		}
		int* getContainer(){
			return container;
		}
};

class workWithArray{
	private:
		int* arrayReceived;
	public:
		workWithArray(int* arrayReceived){
			anArray testArray(3);
			testArray.insertValue(23);
			testArray.insertValue(25);
			testArray.insertValue(3);
			this->arrayReceived = arrayReceived;
			for(int i = 0; i<6; i++){
				cout << arrayReceived[i] << endl;;
			}
			for(int i = 0; i<3; i++){
				cout << testArray.getContainer()[i] << endl;;
			}
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	anArray arrayOne(5);
	for(int i = 0; i<6; i++){
		arrayOne.insertValue(i);
	}
	cout << arrayOne.getSize() << endl;
	cout << arrayOne.getCapacity() << endl;

	workWithArray arrayTwo(arrayOne.getContainer()); 

	return 0;
}

class dynamicArray{
	private:
		int capacity; 
		int* container;
		int size; //placeholder in array
		int value;
	public:
		dynamicArray(int capacity){
			this->container = new int[capacity][capacity]; //how to get to the second row? first pointer will point to the second row
															// 2nd pointer points to place in array[position][position]
			//now we have pointer ->[0][1][2][3][4][5] 2nd row pointer->[0][1][2][3][4][5] pointer->[0][1][2][3][4][5]
			this->capacity = capacity;
			this->size = 0;
		}
		~dynamicArray(){
			delete [] container;
		}
		void takeValue(int number){
			container[size] = number;
			size++; //now its at 1
			size == capacity?
				//no more room
			//increase your capacity
			increaseCapacity();
		}
		int* (a pointer array) getArray(){
			return container;
		}
		
		int (an array)
		void increaseCapacity(){
			//double the capacity
			container = new int[capacity*2];
		}
};

class getMeYourArray{
		private:
			int blah;
		public:
			void workWithSomeArray{
				dynamicArray object;
				int tempContainer[x][y] = object.getArray()[3][4]; //return an array to work with
				//do stuff with tempContainer 
				//happy!
			}
}
void passMeAnArray(int* someArraysAddress){
	work with value however you like 
	//done
}

int main(){
	
	int someArray[4][4] = {1, 2, 3, 4};
	
	
	int value;
	
	passMeAnArray(&value, int position);

	return;
}
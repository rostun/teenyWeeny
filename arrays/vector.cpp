//1D vector

#include <vector>

int main(){
	
	vector <int> example;

	for(int i = 0; i<5; i++){
		example.push_back(i);
		cout << example[i] << endl;
	} 

	example.erase(example.begin()+4);
	cout << example.front() << endl;
	cout << example.back() << endl;

	return 0;
}

//2D value_type
int main(){
	
	return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int numbers, rotations;
    cin >> numbers >> rotations;
    
    int input;
    vector <int> array;
    for(int i = 0; i < numbers; i++){
        cin >> input;
        array.push_back(input);
    }
    
    //start number = rotations/numbers + rotations
    int start = rotations%numbers; //cout << "start: " << start << endl;
    
    for(int i = 0; i < numbers; i++){
        if(i == numbers-1){
            cout << array[start];
        } else {
            cout << array[start] << " ";
        }
        start++;
        if(start >= numbers){
            start = 0;
        }

    }
    
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {  
    int n, k, q;
    
    cin >> n >> k >> q;
    
    int num;
    vector <int> numbers;
    
    //take in user numbers
    for(int i = 0; i < n; i++){
        cin >> num;
        numbers.push_back(num);
    }
    
    k = k%numbers.size();
    //take in indices, do rotation
    for(int i = 0; i < q; i++){
        cin >> num;
        if(num-k < 0){
            cout << numbers[(num-k) + numbers.size()] << endl;
        } else {
            cout << numbers[num-k] << endl;  
        }
        
    }   
    
    return 0;
}
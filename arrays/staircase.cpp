#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    int counter = n-1;
    int hash = 1;
    int hashWhile = 0;
        
    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j == counter){
                while(hashWhile < hash){
                    cout << "#";
                    hashWhile++;
                }
                hashWhile = 0;
                hash++;
                counter--;
            } else {
                cout << " ";
            } 
        }
        cout << endl;
    }
    return 0;
}
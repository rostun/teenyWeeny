#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
   
    int sumRight = 0;
    int sumLeft = 0;
    int countLeft = n-1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                sumRight = sumRight + a[i][j];
            }
            if(j == countLeft){
                sumLeft = sumLeft + a[i][j];
                countLeft--;
            }
        }  
    }
    
    int difference;
    //cout << "sumRight: " << sumRight << endl;
    //cout << "sumLeft: " << sumLeft << endl;
    difference  = abs(sumRight-sumLeft);
    cout << difference << endl;
    
    return 0;
}
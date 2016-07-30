//either use a library or store the numbers as strings and do the calculations yourself (elementary school way) 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int alteredFib(long long int t1, long long int t2, long long int n, vector <long long int>& memo);

int main() {
    long long int t1, t2, n;
    
    
    cin >> t1 >> t2 >> n;
    vector <long long int> memo(n, 0);
    
    cout << alteredFib(t1, t2, n-1, memo);
    
    return 0;
}

long long int alteredFib(long long int t1, long long int t2, long long int n, vector<long long int> &memo){

    if(n == 0){
        return t1;
    }
    if(n == 1){
        return t2;
    }
    
    if(memo[n] == 0){
        memo[n] = alteredFib(t1, t2, n-2, memo) + pow(alteredFib(t1, t2, n-1, memo), 2); 
        cout << "memo[" << n << "]: " << memo[n] << endl;
    }
    
    return memo[n];
}
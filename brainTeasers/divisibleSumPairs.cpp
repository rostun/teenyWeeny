#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }   
    
    int numPairs = 0;
    double divide;
    
    //don't have to look at n-1, save a loop
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            divide = (a[i]*1.0 + a[j])/k;
            //cout << divide << endl;
            if(divide == int(divide)){
                numPairs++;
            }
        }    
    }
    
    cout << numPairs << endl;
    
    return 0;
}

//O(n) time
/*
	Basically any number 'x' when divided by 'k' leaves a remainder from 0 to k-1. 
	Take an example where k=8 and the 2 numbers are 21 and 27. 
	Now 21+27=48 which divided by 8 gives 0 remainder. 
	21=16+5 where 5 is the remainder when 21 is divided by 8 and likewise 3 for 27/8. 
	So 21+27=16+24+(5+3)....so jst add those numbers whose remainder sum equals k
	
	It doesnt have to know...the condition is not necessary. It doesnt matter if 21 
	comes before or after 27. the code seperates all numbers based on their remainder. 
	a[i]+a[j] is the same as a[j]+a[i], regardless of the values of i and j .The array 
	elements are increased only once when a number is encountered.... So the code will 
	make pairs of elements of the rem array only once... P.S-the condition is required 
	in the code only when it is written in O(n^2) .
*/

int rem[100]; 
for(int i=0;i<k;i++){
    rem[i]=0;
}

//tally remainders in vector 
for(int i=0;i<n;i++){
    int z = a[i]%k; 
    rem[z]++;  
}

//half of zeroTallies*(zeroTallies-1)
int l=((rem[0]*(rem[0]-1))/2) ;

for(int i=1;i<=k/2;i++){   
	if(i!=(k-i)){
		l+=(rem[i]*rem[k-i]);		
	} else {
		l+=((rem[i]*(rem[i]-1))/2);
	}
}

cout<<l;





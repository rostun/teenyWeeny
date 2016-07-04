#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int testCases;
    cin >> testCases;
    int numPrisoners, numSweets, startingPrisoner;
    int leftOver, deadPrisoner;
    int prevPrisoner = 0;
    vector <int> rounds;
    
    while(testCases > 0){
        cin >> numPrisoners >> numSweets >> startingPrisoner;
        leftOver = numSweets % numPrisoners; //tells me how many rounds i can get rid of
        if(leftOver == 0){
            deadPrisoner = startingPrisoner - 1;
            if(deadPrisoner <= 0){
                deadPrisoner = numPrisoners;
            }
        } else { //leftOver is not equal to zero
            deadPrisoner = startingPrisoner + leftOver - 1;
            if(deadPrisoner > numPrisoners){
                deadPrisoner = deadPrisoner - numPrisoners;
            }
        }
        rounds.push_back(deadPrisoner);
        testCases--;
    }
    
    for(int i = 0; i<rounds.size(); i++){
        cout << rounds[i] << endl;
    }
    
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int testCases;
    cin >> testCases;
    int numPrisoners, numSweets, startingPrisoner;
    int currentPrisoner, nextPrisoner, prevPrisoner;
    
    while(testCases > 0){
        cin >> numPrisoners >> numSweets >> startingPrisoner;
        while(numSweets > 0){
            //cout << "prisoner: " << startingPrisoner << endl;
            //cout << "sweets: " << numSweets << endl;
            prevPrisoner = startingPrisoner;
            if(startingPrisoner == numPrisoners){
                startingPrisoner = 1;
            } else {
                startingPrisoner++;
            }   
            numSweets--; //give a sweet
        }
        //since we end up with the next prisoner at the end of the loop, -1
        cout << prevPrisoner << endl; 
        testCases--;
    }
    
    return 0;
}
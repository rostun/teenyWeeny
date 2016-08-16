#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string line;
    cin >> line;
    
    char test = line[0];
    int i = 0;
    
    while(test != ';'){
        i++;
        test = line[i];
    }
    
    int number;
    vector <int> numbers;
    test = line[i++];
    string a = "";
    
    //go through rest of string
    while(line[i] != '\0'){ //test line[i]
        test = line[i]; 
        //if we hit a comma, need to push back number
        if(test == ','){
            number = atoi(a.c_str());
            numbers.push_back(number);
            test = line[i++];
            a = "";
        } 
        //if we didn't we're not done yet
        else {
            a+=test;
            i++;
        }
    }
    
    //push back last number
    number = atoi(a.c_str());
    numbers.push_back(number);
    
    sort(numbers.begin(), numbers.end());
    int A = numbers[0];
    int B;
    
    for(int i = 1; i < numbers.size(); i++){
        B = numbers[i];
        if(A == B){
            cout << A << endl;
            return 0;
        } else {
            A = B;
        }
    }
    
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even", "odd"};
    int a, b, c;
    cin >> a;
    cin >> b;
    c = b-a;
    for(int i = 0; i <= c; i++){
        if(a > 9){
            if(a%2 == 0){
                cout << arr[9] << endl;
            } else {
                cout << arr[10] << endl;
            }
        } else {
            cout << arr[a-1] << endl;
        }
        a++;
    }
    return 0;
}
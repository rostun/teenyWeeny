#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n;
    int num;
    stack <int> things;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        things.push(num);
    }
    
    while(things.size() > 0){
        cout << things.top() << " ";
        things.pop();
    }
    return 0;
}
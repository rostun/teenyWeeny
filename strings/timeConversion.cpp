#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    int hours;
    string holder;
    string minutes;
    string seconds;
    string moment;    
    
    holder = holder + time[0] + time[1];
    hours = stoi(holder);
    
    minutes = minutes + time[3] + time[4];
    seconds = seconds + time[6] + time[7];
    moment = moment + time[8] + time[9];
    
    if(moment == "PM"){
        if(hours != 12){
            hours = hours + 12;
            if(hours > 23){
                hours = hours-24;
            }           
        }
    } else {
        if(hours == 12){
            hours = 0;
        }
    }
    
    if(hours < 10){
        cout << "0";
    }
    cout << hours << ":" << minutes << ":" << seconds << endl;
    
    return 0;
}

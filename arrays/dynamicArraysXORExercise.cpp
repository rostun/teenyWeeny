#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    int lastAns = 0;
    
    cin >> N >> Q;
    
    vector <vector<int>> arr(N, vector<int>()); //N empty lists
 
    int queryType, x, y, size;
	vector <int> lastAnswers;
    int loops = 0;
    
    while(loops < Q){
        cin >> queryType >> x >> y;
		if(queryType == 1){
			arr.at((x ^ lastAns)%N).push_back(y);
		} else {
			size = arr[(x ^ lastAns)%N].size();
			lastAns = arr[(x ^ lastAns)%N][y%size];
			lastAnswers.push_back(lastAns);
		}
		loops++;
    }
    
	for (int i =0; i<lastAnswers.size(); i++){
		cout << lastAnswers[i] << endl;
	}

    return 0;
}
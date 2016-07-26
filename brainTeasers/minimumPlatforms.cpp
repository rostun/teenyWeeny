#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinGates(vector <int> arrivals, vector <int> departures, int flights);

// Driver program to test methods of graph class
int main()
{
	int num = 2;
    int arr[] = {900,910,920};
	vector <int> arrivals(arr, arr+num);
    int dep[] = {930,915,925};
	vector <int> departures(dep, dep+num);
    cout << "Minimum Number of Platforms Required = "
         << findMinGates(arrivals, departures, num);
    
	cin.get();
	return 0;
}

int findMinGates(vector <int> arrivals, vector <int> departures, int flights){
	sort(arrivals.begin(), arrivals.end());
	sort(departures.begin(), departures.end());
	
	int arr = 0;
	int dep = 0;
	int gates = 0;
	int maxGates = 1;
	
	//while
	while(arr < flights && dep < flights){
		//if next is arrival, increment count of platforms needed
		if(arrivals[arr] <= departures[dep]){
			gates++; // we need another gate
			arr++;
			if(gates > maxGates){
				maxGates = gates; //update the result
			}
		}
		//else get rid of a gate
		else {
			gates--;
			dep++;
		}
	}
	
	return maxGates;
}
}
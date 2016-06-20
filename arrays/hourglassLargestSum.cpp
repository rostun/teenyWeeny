using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    
    int largestSum; //keep track of largest sum
    int currentSum; //compare to this
    
    for(int x = 0; x<4; x++){ //rows
        for(int y = 0; y<4; y++){ //columns
            //sum of current hourglass we're looking at
            currentSum = arr[x][y] + arr[x][y+1] + arr[x][y+2] +
                         arr[x+1][y+1] +
                         arr[x+2][y] + arr[x+2][y+1] + arr[x+2][y+2];
            //cout << "sum: " << currentSum << endl;
            if(x == 0 && y == 0){ //largest sum is whatever that is
                largestSum = currentSum;
            } else {//compare largest sum to current sum
                if(currentSum > largestSum){
                    largestSum = currentSum;
                }
            }
        }
    }
    
    cout << largestSum;
    
    return 0;
}
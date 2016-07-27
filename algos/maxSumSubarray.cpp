//find longest subarray that is less than a given sum k (a[i] >= 1)

int maxLength(vector < int > a, int k) {
    int maxLength = 0;
    int currLength = 1;
    int currSum = a[0];
    
    int start = 0;
    int end = 0;
    
    //loop through until we
    while(start < a.size() && end < a.size()){     
        //if we found a subarray <= to (k=something)
        if(currSum <= k){
            //replace maxLength if need be
            if(currLength > maxLength){
                maxLength = currLength;
            }
            end++;
            currSum = currSum + a[end];
            currLength++;
        }
        //if we're over our max we need to move our start up, as well as updating our length
        else{
            currSum = currSum - a[start];
            start++;
            currLength--;
        }
    }
    
    return maxLength;
}
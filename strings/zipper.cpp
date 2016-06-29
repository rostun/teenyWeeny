// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//test cases: (54321, 54321), (0, 0), (1, 12345), (12345, 1), (0, 12345) 
int solution(int A, int B) {
    long decimalZip;
    
    //convert A and B into strings
    string a = to_string(A); //cout << "a: " << a << endl;
    string b = to_string(B); //cout << "b: " << b << endl;
    
    int aLength = a.length(); //cout << "a.length: " << aLength << " " << a[0] << " " << a[1] << endl;
    int bLength = b.length(); //cout << "b.length: " << bLength << endl;
    int aZip = 0;
    int bZip = 0;
    
    //concatenate A, then B  appropriately
    string decimal;
    while(aZip < aLength || bZip < bLength){
       if(aZip < aLength){
           decimal = decimal + a[aZip];
           aZip++;
       }
       if(bZip < bLength){
           decimal = decimal + b[bZip];
           bZip++;
       }
    } //cout << "decimal: " << decimal << endl;
    
    //change it into whatever number it is
    decimalZip = stol(decimal);
    
    //make sure the result does not exceed 100,000,000
    if(decimalZip >= 100000000){
        decimalZip = -1;
    }
    
    return decimalZip;
}
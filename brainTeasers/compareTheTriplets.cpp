using namespace std;

void compare(int &a, int &b);

int main(){
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    
    int alicePoints = 0;
    int bobPoints = 0;
    
    compare(a0, b0);
    alicePoints += a0;
    bobPoints += b0;
    
    compare(a1, b1);
    alicePoints+=a1;
    bobPoints += b1;
    
    compare(a2, b2);
    alicePoints+=a2;
    bobPoints += b2;
    
    cout << alicePoints << " " << bobPoints << endl;
    return 0;
}

void compare(int &a, int &b){ //0 1 2
    int A = 0;
    int B = 0;
    
    if(a > b){
        A = 1;
    }
    
    if(a < b){
        B = 1;
    }
    
    a = A;
    b = B;
}
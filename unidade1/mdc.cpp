#include <iostream>
using namespace std;

int mdc(int a, int b){
    int temp = a;
    a -= b;
    b = temp;
    if(a <= 0){
        return b;
    }
    else{
        return mdc(a,b);
    }
}

void ordem(int &a , int &b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
}

int main(){
    int x, y;
    cin >> x >> y;
    ordem(x,y);
    cout << mdc(x,y);
    return 0;
}
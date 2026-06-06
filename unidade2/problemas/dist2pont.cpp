#include <cmath>
#include <iostream>
using namespace std;

float distP(float a, float b, float c, float d){
    float res = sqrt(pow(a-c,2)+ pow(b-d,2));
    return res ;
}

int main(){
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << distP(a, b, c, d);



    return 0;
}
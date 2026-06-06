#include <iostream>
using namespace std;

int main(){
    int n, t, b, e;
    long long sum = 0;
    

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> t;
        b = t / 10;
        e = t % 10;

        int res = 1;
        for(int j = 0; j < e; j++)res *= b;
        sum += res;
    }
    cout << sum;


    return 0;
}
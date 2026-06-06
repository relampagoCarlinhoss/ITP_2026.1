#include <iostream>
using namespace std;

int main(){
    int j, p, v, e, d;
    
    cin >> j >> p >> v >> e >> d;

    for(int i = 0; i < 5; i++){
        
        if(j == -1 && v != -1 && e != -1 && d != -1) j = v + e + d;
        if(v == -1 && j != -1 && e != -1 && d != -1) v = j - e - d;
        if(e == -1 && v != -1 && j != -1 && d != -1) e = j - v - d;
        if(d == -1 && v != -1 && e != -1 && j != -1) d = j - v - e;
        if(p == -1 && v != -1 && e != -1) p = 3 * v + e;
        if(v == -1 && p != -1 && e != -1) v = (p - e)/3;
        if(e == -1 && v != -1 && p != -1) e = p - (3 * v);
        if(v == -1 && e == -1 && j != -1 && p != -1 && d != -1){
            v = (p - j + d)/2;
            e = j - v - d; 
        }
    }

    cout << j << " " << p << " "  << v << " " << e << " " << d;

    return 0;
}
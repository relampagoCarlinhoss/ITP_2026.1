#include <iostream>
using namespace std;

int main(){
    int caps, moed;
    int moedI = 0; 

    cin >> caps >> moed;

    int vetT[caps];

    for(int i = 0; i < caps; i++) cin >> vetT[i];
    
    int d = 1;

    while(true){
        for(int i = 0; i < caps; i++){
            if(d % vetT[i] == 0) moedI++;
    }
        if(moedI>=moed) break;
        d++;
}
    cout << d;

    return 0;
}
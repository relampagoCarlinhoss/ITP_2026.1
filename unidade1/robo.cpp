#include <iostream>
using namespace std;

int main(){
    int e, c, d;
    int pos = 1;
    int res = 0;

    cin >> e >> c >> d;

    if(d == 1) res++;

    int vetC[c];

    for(int i = 0; i < c; i++) cin >> vetC[i]; 

    for(int i = 0; i < c; i++)
    {
        if(vetC[i] == 1){
            if(pos == e) pos = 1;
            else pos++;
        }
        if(vetC[i] == -1){
            if(pos == 1) pos = e;
            else pos--;
        }

        if(pos == d) res++;
    }
    cout << res;


    return 0;
}
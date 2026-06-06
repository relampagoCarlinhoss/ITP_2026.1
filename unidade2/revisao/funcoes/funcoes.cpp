#include <iostream>
using namespace std;
bool intersec(int ponto[2], int re[2], int rd[2]){
    bool intersec = false;
    if(re[0] < ponto[0] && ponto[0] < rd[0]){
        if(re[1] > ponto[1] && rd[1] < ponto[1]){
            return true;
        }
    }
    return false;
}

int main(){
    int ponto[2];
    int re[2];
    int rd[2];

    for (int i = 0; i < 2; i++) cin >> ponto[i];
    for (int i = 0; i < 2; i++) cin >> re[i];
    for (int i = 0; i < 2; i++) cin >> rd[i];

    intersec(ponto, re, rd);
    return 0;
}
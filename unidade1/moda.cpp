#include <iostream>
using namespace std;

int main(){
    int n, freq;
    int moda = 0;

    cin >> n;

    int vet1[n], vetf[n];
    //atribuição
    for(int i = 0; i < n; i++){
        cin >> vet1[i];
    }
    //frequencias
    for(int i = 0; i < n; i++){
        freq = 0;
        for(int j = 0; j < n; j++){
            if(vet1[i] == vet1[j]){
            freq++;
            }
        }
        vetf[i] = freq;
    }
    //pegar valor de maior indice
    for (int i = 0; i < n; i++){
        if( vetf[i]>vetf[moda])moda = i;
    }
    cout << vet1[moda];
    
   return 0;
}
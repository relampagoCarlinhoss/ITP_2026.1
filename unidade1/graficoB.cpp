#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int maior = 0;
    cin >> n;

    int ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];

    //pegar o maior
    for(int i = 0; i < n; i++){
        if(ar[i] > maior) maior = ar[i];
    }
    
    //matriz de saida
    int matriz[maior][n];
     for(int i = 0; i < maior; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = 0;
        }
    }
    
    //atribuição
    int i = 0;
    do{
       for(int j = maior - (ar[i]); j < maior; j++){
            matriz[j][i] = 1;
       }
       i++;
    }while(i < n);
    //impressão
    for(int i = 0; i < maior; i++){
        for(int j = 0; j < n;j++) cout << matriz[i][j]<< " ";
        cout << "\n";
    }
}
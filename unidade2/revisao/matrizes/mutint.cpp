#include <iostream>
using namespace std;

int main(){
    int linha = 0, coluna = 0, k = 0;
    cin >> linha >> coluna;
    cin >> k;

    int matriz[linha][coluna];

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cin >> matriz[i][j];
            matriz[i][j] = k*matriz[i][j];
        }
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cout << matriz[i][j] << " ";
            if(j == coluna - 1) cout << "\n";
        }
    }

    return 0;
    }
#include <iostream>
using namespace std;


int main(){
    int linha1, coluna1, linha2, coluna2;
    cin >> linha1 >> coluna1 >> linha2 >> coluna2;
    
    if(coluna1 != linha2){
        cout << "nao dá pra mutiplicar";
        return 0;
    }

    int matriz1[linha1][coluna1];
    int matriz2[linha2][coluna2];
    int matrizR[linha1][coluna2];

    for(int i = 0; i < linha1; i++){
        for(int j = 0; j < coluna1; j++){
            cin >> matriz1[i][j];
        }
    }

    for(int i = 0; i < linha2; i++){
        for(int j = 0; j < coluna2; j++){
            cin >> matriz2[i][j];
        }
    }

    for(int i  = 0; i < linha1; i++){
        for(int j = 0; j < coluna2; j++){
            matrizR[i][j] = 0;
        }
    }
    
    int mL1 = 0, mC2 = 0;
    for(int i = 0; i < linha1; i++){
        for(int j = 0; j < coluna1; j++){
            for(int k = 0; k < coluna2; k++){
                matrizR[i][k] += matriz1[i][j]*matriz2[j][k];
        }
        }
    }
    for(int i = 0; i < linha1; i++){
        for(int j = 0; j < coluna2; j++){
            cout << matrizR[i][j] << " ";
            if(j == coluna2 - 1) cout << "\n";
        }
    }
    return 0;
}
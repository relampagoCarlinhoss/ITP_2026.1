#include <iostream>
using namespace std;

int main(){
    int linha = 0, coluna = 0;
    cin >> linha >> coluna;

    int matrizA[linha][coluna];
    int matrizT[coluna][linha];
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cin >> matrizA[i][j];
            matrizT[j][i] = matrizA[i][j];
        }
    }

    for(int i = 0; i < coluna; i++){
        for(int j = 0; j < linha; j++){
            cout << matrizT [i][j] << " "; 
            if(j == linha - 1) cout << "\n";
            
        }
    }


    return 0;
}
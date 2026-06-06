#include <iostream>
using namespace std;

int main(){
    int linha, coluna;
    cin >> linha >> coluna;
    
    int matriz1[linha][coluna];
    int matriz2[linha][coluna];

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cin >> matriz1[i][j];
        }
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cin >> matriz2[i][j];
            matriz2[i][j] += matriz1[i][j];
        }
    }
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cout << matriz2[i][j] << " ";
            if(j == coluna - 1) cout << "\n";
        }
    }



    return 0;
}
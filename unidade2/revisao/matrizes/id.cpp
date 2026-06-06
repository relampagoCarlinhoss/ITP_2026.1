#include <iostream>
using namespace std;

int main(){
    int linha, coluna;
    bool ehIdentidade = true;
    cin >> linha >> coluna;

    int matriz[linha][coluna];

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cin >> matriz[i][j]; 

            if(i == j){
                if(matriz[i][j] != 1){
                    ehIdentidade = false; 
                    break;
                }
            }
            else{
                if(i != j){
                    if(matriz[i][j] != 0){
                        ehIdentidade = false;
                        break;
                    }
                }
            }

        }
        if(ehIdentidade == false){
            break;
        }
    }
     
    (ehIdentidade) ? (cout << "é identidade"): (cout << "não é identidade");
    return 0;
}
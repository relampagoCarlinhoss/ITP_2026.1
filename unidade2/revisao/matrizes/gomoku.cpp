#include <iostream>
using namespace std;

int main(){
    int tabuleiro[15][15];

    bool vitoriaP = false;
    bool vitoriaB = false;
    bool empate = false;

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
        cin >> tabuleiro[i][j]; 
        }
    }


    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(tabuleiro[i][j] != 0){
                
                //ganha nas colunas
                if((j+ 4) < 15){
                    if(tabuleiro[i][j] + tabuleiro[i][j+1] + tabuleiro[i][j+2] + tabuleiro[i][j+3] + tabuleiro[i][j+4] == 10){
                        vitoriaB = true;
                        break;
                    }
                    
                    if(tabuleiro[i][j] + tabuleiro[i][j+1] + tabuleiro[i][j+2] + tabuleiro[i][j+3] + tabuleiro[i][j+4] == 5){
                        vitoriaP = true;
                        break;
                    }
                }

                if((j - 4) > -1){
                     if(tabuleiro[i][j] + tabuleiro[i][j - 1] + tabuleiro[i][j - 2] + tabuleiro[i][j - 3] + tabuleiro[i][j - 4] == 10){
                        vitoriaB = true;
                        break;
                    }
                    
                    if(tabuleiro[i][j] + tabuleiro[i][j - 1] + tabuleiro[i][j - 2] + tabuleiro[i][j - 3] + tabuleiro[i][j - 4] == 5){
                        vitoriaP = true;
                        break;

                    }
                }
            }
         
            //ganha nas linhas
            if(i + 4 < 15){
                if(tabuleiro[i][j] + tabuleiro[i + 1][j] + tabuleiro[i + 2][j] + tabuleiro[i + 3][j] + tabuleiro[i + 4][j] == 10){
                        vitoriaB = true;
                        break;
                }
                    
                if(tabuleiro[i][j] + tabuleiro[i + 1][j] + tabuleiro[i + 2][j] + tabuleiro[i + 3][j] + tabuleiro[i + 4][j] == 5){
                        vitoriaP = true;
                        break;
                }
            }

            if(i - 4 > -1){
                 if(tabuleiro[i][j] + tabuleiro[i -1][j] + tabuleiro[i - 2][j] + tabuleiro[i - 3][j] + tabuleiro[i - 4][j] == 10){
                        vitoriaB = true;
                        break;
                }
                
                if(tabuleiro[i][j] + tabuleiro[i - 1][j] + tabuleiro[i -2][j] + tabuleiro[i - 3][j] + tabuleiro[i - 4][j] == 5){
                        vitoriaP = true;
                        break;
                }
            }
            
            //nas diagonais
            if(i + 4 < 15 && j + 4 < 15){
                 if(tabuleiro[i][j] + tabuleiro[i + 1][j + 1] + tabuleiro[i + 2][j + 2] + tabuleiro[i + 3][j + 3] + tabuleiro[i + 4][j + 4] == 10){
                        vitoriaB = true;
                        break;
                }
                    
                if(tabuleiro[i][j] + tabuleiro[i + 1][j + 1] + tabuleiro[i + 2][j + 2] + tabuleiro[i + 3][j + 3] + tabuleiro[i + 4][j + 4] == 5){
                        vitoriaP = true;
                        break;
                }
            }

            if(i - 4 > -1 && j - 4 > -1){
                if(tabuleiro[i][j] + tabuleiro[i -1][j - 1] + tabuleiro[i - 2][j - 2] + tabuleiro[i - 3][j - 3] + tabuleiro[i - 4][j - 4] == 10){
                        vitoriaB = true;
                        break;
                }
                
                if(tabuleiro[i][j] + tabuleiro[i - 1][j - 1] + tabuleiro[i - 2][j] + tabuleiro[i - 3][j - 3] + tabuleiro[i - 4][j - 4] == 5){
                        vitoriaP = true;
                        break;
                }
            }
        }
        if(vitoriaB || vitoriaP){
            break;
        }
    }

    if(!(vitoriaP || vitoriaB)){
        empate = true;
    }
    
    if(empate) cout << "0";
    else if(vitoriaP) cout << "1";
    else cout << "2";
    
        
    return 0;
        }
#include <iostream>
using namespace std;

int main(){
    int m, n;
    int maiorV, menorV;

    cin >> m >> n;

    //achar o maior e menor valor
    if(m >= n){
        maiorV = m;
        menorV = n;
    }
    else{
        maiorV = n;
        menorV = m;
    }

    //atribuir array
    int vet1[maiorV], vet2[menorV];

    for (int i = 0; i < maiorV; i++){
        cin >> vet1[i];
    }
    for (int i = 0; i < menorV; i++){
        cin >> vet2[i];
    }
   
    //achar os iguais
    for(int i = 0; i < menorV; i++){
        for(int j = 0; j < maiorV; j++){
            if( vet2[i] == vet1[j]){
                cout << vet2[i] << " ";
                break;
            }

        }

    }

    return 0;

}
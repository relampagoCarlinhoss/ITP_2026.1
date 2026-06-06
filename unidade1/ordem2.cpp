#include <iostream>
using namespace std;

int main(){
    int m, n, maiorL, menorL;
    int k=0;

    cin >> m >> n;

    if(m >= n){
        maiorL = m;
        menorL = n;
    }
    else{
        maiorL = n;
        menorL = m;
    }

    int sum = maiorL + menorL;
    int dif = maiorL-menorL;

    int vet1[maiorL], vet2[menorL], vet3[sum];
    
    //atribuição
    for(int i1 = 0; i1 < maiorL; i1++){
        cin >> vet1[i1]; 
    }
    for(int i2 = 0; i2 < menorL; i2++){
        cin >> vet2[i2];
    }
    //atribuição

    for(int i = 0; i < menorL; i++){
        vet3[i] = vet2[i];
    }
    for(int i = 0; i < maiorL; i++){
        vet3[menorL+i] = vet1[i];
    }
    for (int i = 0; i < sum; i++){
        for(int j = i + 1; j < sum; j++){
            if(vet3[j] < vet3[i]){
                int tempM = vet3[i];
                vet3[i] = vet3[j];
                vet3[j] = tempM;
            }
        }
    }
    for(int i = 0; i < sum; i++){
        cout << vet3[i] << " ";
    }
    return 0;
}
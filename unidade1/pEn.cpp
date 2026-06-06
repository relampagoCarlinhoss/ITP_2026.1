using namespace std;
#include <iostream>

int main(){
    int m, p;

    cin >> m >> p;
    
    p--;
    int vet1[m];

    //atribuição
    for(int i = 0; i < m; i++){
        cin >> vet1[i];
    }

    //ordenamento decrescrente
    for(int i = 0; i < m; i++){
        for(int k = i+1; k < m; k++){
            if(vet1[i] < vet1[k]){
                int temp = vet1[i]; 
                vet1[i] = vet1[k];
                vet1[k] = temp;
            }
        }
    }

    //p-enesimo valor
    for(int i = 0; i < m; i++){
        cout << vet1[i] << "\n";
    }
    cout << vet1[p] <<"\n";
    

    return 0;
}
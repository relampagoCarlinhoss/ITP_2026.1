#include <iostream>
using namespace std;

int main(){
    int m;

    cin >> m;

    int vetor1[m];

    for (int contv1 = 0; contv1 < m; contv1++){
        cin >> vetor1[contv1];
    }

    for (int cont2 = 0; cont2 < m; cont2++){

        for (int cont3 = (cont2)+1; cont3 < m; cont3++){
                
            if (vetor1[cont3] < vetor1[cont2]){
                   int temp = vetor1[cont2];
                   vetor1[cont2] = vetor1[cont3];
                   vetor1[cont3] = temp;
            }
            }
    }
    
    for(int cont = 0; cont<m; cont++){
        cout << vetor1[cont] << "\n";
    }
    return 0;
}
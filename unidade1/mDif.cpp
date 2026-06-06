#include <iostream>
using namespace std;

int main(){
    int m;

    cin >> m;

    int vet[m];
    int vetDif[m];

    for(int i = 0; i < m; i++){
        cin >> vet[i];
        vetDif[i]=vetDif[i]+1;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(j == m)continue;
            vetDif[i] = vet[i] - vet[j];
            if((vetDif[j]<=vetDif[i])){
                int temp = vetDif[i];
                vetDif[i] = vetDif[j];
                vetDif[j]=temp;
            }
        }
    }
    cout << vetDif[0];

    return 0;
}
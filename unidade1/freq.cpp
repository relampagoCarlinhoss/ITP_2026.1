#include <iostream>
using namespace std;

int main(){
    int m, freq;
    bool lgc;
    cin >> m;

    int vet[m];
    
    for(int i = 0; i < m; i++){
        cin >> vet[i];
    }
    
    for (int i = 0; i < m; i++){
        lgc = false;
        for(int k = 0; k < i; k++){
            if(vet[i] == vet[k]){
                lgc = true;
                break;
            }
        }
        if(lgc == true) continue;

        freq = 0;
        for( int j = 0; j < m; j++){
            if( vet[i] == vet[j]){
                freq++;
            }
        }
        cout << vet[i] << ":" << freq << " ";
    }



    

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int casos;
    int tropa;
    int soma = 0;
    int cont1 = 0;
    int cont2 = 0;

    cin >> casos;
    
    int vTropa[casos];

    while(cont1 < casos){
        cin >> tropa;
        
        cont2 = 0;
        soma = 0;

        for(int i = 1; soma < tropa; i++){
            soma += i;
            cont2++;
        }
        if( soma != tropa){
            vTropa[cont1] = cont2 -1 ;
            cont1++;
        }else{
            vTropa[cont1] = cont2;
            cont1++;
        }
    }

    for(int i = 0; i < casos; i++){
        cout << vTropa[i] << "\n";
    }
   
    
    return 0;
}
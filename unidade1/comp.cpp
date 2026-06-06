#include <iostream>
using namespace std;

int main(){
    int leng;
    bool dif=true;

    cin >> leng;

    int vetor[leng]; 
    
    for(int cont=0;cont<leng;cont++){
        cin >> vetor[cont];
    }

    for(int cont1 = 0; cont1 < leng; cont1++){
        dif=true;

        for(int cont2 = 0; cont2 < leng; cont2++){
            
            if(cont2 == cont1) continue;

            if(vetor[cont1] == vetor[cont2]){
                dif=false;
                break;
        } 
    }
    
    if(dif==true){
        cout << vetor[cont1];
    }
}


    return 0;
}
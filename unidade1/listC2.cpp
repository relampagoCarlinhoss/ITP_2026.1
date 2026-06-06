#include <iostream> 
using namespace std;

int main(){
/*    //a1, t2, c5, q4, p3

    int n;
    int soma = 0;
    
    cin >> n;

    int item[n];

    for(int i = 0; i < n; i++) cin >> item[i];

    for(int i = 0; i < n; i++){
        if(item[i] == 1) soma += 1;
        if(item[i] == 2) soma += 2;
        if(item[i] == 3) soma += 5;
        if(item[i] == 4) soma += 4;
        if(item[i] == 5) soma += 3;
    }
    cout << soma;
    return 0;
}*/
   /* int itens, custos;
    int soma = 0;

    cin >> custos >> itens;

    int vetC[custos];
    int vetI[itens];

    for(int i = 0; i < custos; i++) cin >> vetC[i];
    for(int i = 0; i < itens; i++) cin >> vetI[i];

    for(int i = 0; i < itens; i++)
    {
        for(int j = 0; j < custos; j++)
        {
            if(vetI[i]-1 == j) soma += vetC[j];
        }
    }
    
    cout << soma;*/

    int qI, qT;
    int qR = 0;

    
    cin >> qI >> qT;

    int vetqI[qI];
    int vetqT[qT];
    
    for(int i = 0; i < qI; i++) cin >> vetqI[i];
    for(int i = 0; i < qT; i++) cin >> vetqT[i];
    
    int k = 0;

    for(int i = 0; i < qT; i++){
        if(vetqI[k] == vetqT[i]){
            k++;
        }

        if(k == qI){
            k = 0;
            qR++;
        }
    }
    cout << qR;
    return 0;
    }
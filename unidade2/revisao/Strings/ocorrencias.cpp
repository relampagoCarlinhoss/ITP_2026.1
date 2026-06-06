#include <iostream>
using namespace std;

int ocorrencias(string a, string b){
    int i = 0;
    int contador = 0;

    while(i < a.size()){
        i = a.find(b, i + 1);
        if(a.find(b, i) == string :: npos) break;
        
        contador++;
    }
    
    return contador;
}

int main(){
    string texto = "ainda bem que nao fui pra faculdade hojenemamanhahoje hoje";
    string ocorrencia = " hoje";
    cout << ocorrencias(texto, ocorrencia);



    return 0;
}
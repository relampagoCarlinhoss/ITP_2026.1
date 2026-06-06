#include <iostream>
using namespace std;

int strsize(char string[]){
    int tamanho = 0;
    while(string[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}

void strconcat(char string[], char stringB[], char stringC[]){
    for(int i = 0; i < strsize(string) + strsize(stringB); i++){
        if(i < strsize(string)){
        stringC[i] = string[i];
        }
        else{
            stringC[i] = stringB[i - strsize(string)];
        }
    }
}

int strsub(char a[], char b[]){
    bool palavra = true;
    int apontador = -12;

    for(int i = 0; i < strsize(a); i++){
        if(a[i] == b[0]){
            apontador = i;
            for(int j = 0; j < strsize(b); j++){
                if(b[j] != a[i + j]) palavra = false;
            }
        }
    }

    if(palavra) return apontador;
    else return -1;
}

int main(){
    char a[] = "ainda nao vou a praia";
    char b[] = "vou";
   
    int apont = strsub(a, b);
    if(apont != -1){
        for(int i = apont; i < strsize(a); i++){
            cout << a[i];
        }
    }
    return 0;
}
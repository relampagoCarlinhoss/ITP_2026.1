/*
Uma prefeitura está organizando um festival com dois tipos de atividades
que se repetem em intervalos fixos de dias: uma acontece a cada I dias e
a outra a cada J dias. Para montar o calendário oficial, a equipe precisa
listar os primeiros dias em que ocorre pelo menos uma das duas atividade.

Sua tarefa é escrever um programa que leia inicialmente três valores:
- N: quantidade de dias a listar;
- I e J: intervalos de dias das atividades.

Em seguida, envie para a saída os N primeiros números naturais que são
múltiplos de I ou de J (ou de ambos).

Exemplos:

Entrada: 4 2 5 → Saída: 2 4 5 6
Entrada: 7 2 5 → Saída: 2 4 5 6 8 10 12
Entrada: 6 3 5 → Saída: 3 5 6 9 10 12
*/

#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    int encontrados=0;
    int dia=1;

    cin >> n >> i >> j;

    while(encontrados<n){

        if((dia % i == 0) || (dia % j == 0)){
            cout << dia <<" ";
            encontrados++;
        }

        dia++;
    }

    return 0;
}
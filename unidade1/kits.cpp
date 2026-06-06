/*
Uma indústria de embalagens precisa montar kits com dois tipos de peças,
A e B, em quantidades fixas. Para evitar sobras, todos os kits devem ter
exatamente a mesma composição e usar todas as peças disponíveis.

Assim, se a empresa tem por exemplo 150 peças do tipo A e 100 peças do
tipo B, o kit ideal seria composto por 3 peças do tipo A e 2 peças do
tipo B, resultando em 50 kits completos, sem sobras.

Sua tarefa é ler dois números inteiros positivos, indicando as quantidades
de itens do tipo A e do tipo B, e determinar a maior quantidade possível
de kits com esses valores.

Dica 1: você deve calcular o máximo divisor comum (MDC) entre os valores.
Dica 2: você pode usar o [algoritmo de Euclides](https://pt.wikipedia.org/wiki/Algoritmo_de_Euclides).
Dica 3: você pode usar o operador % para calcular o resto da divisão
entre dois números.

Exemplos:

Entrada: 2 4 → Saída: 2
Entrada: 12 38 → Saída: 2
Entrada: 18 9 → Saída: 9
Entrada: 150 100 → Saída: 50


Dados dois números inteiros positivos, determinar o máximo divisor comum entre eles.
Dica: utilize o 

Exemplo:
| Entrada | Saída esperada |
| --------|----------------|
| 2 4     | 2              |
| --------|----------------|
| 12 38   | 2              |
| --------|----------------|
| 18 9    | 3              |
| --------|----------------|
| 150 100 | 50             |
| --------|----------------|
*/


#include <iostream>
using namespace std;

int main() {
    int a,b,r;

    cin >> a >> b;

    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    cout << a << "\n";
}
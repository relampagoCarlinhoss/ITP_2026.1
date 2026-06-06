using namespace std;
#include <string>
/*
## Cume

Em uma das fases do jogo "Gelado", o Rei Gelado precisa ir para o ponto mais alto de sua ilha. Porém, ele não tem uma visão completa do mapa, e só consegue ver apenas seus vizinhos imediatos (cima, esquerda, direita e baixo). Então, pra ele ir ao ponto mais alto, com sua visão limitada, ele adota a seguinte estratégia:
- se não houver nenhum vizinho mais alto que o ponto onde ele está, ele para (já está no mais alto);
- se houver um vizinho mais alto (cima, esquerda, direita e baixo), ele vai para o vizinho mais alto. Caso haja mais de um vizinho mais alto (mais de um ponto com a mesma altitude), ele vai para o último vizinho mais alto que encontrar (o Rei Gelado olha para os vizinhos na seguinte sequência: cima, esquerda, direita e baixo).

Sua tarefa na equipe de desenvolvimento do jogo é implementar uma função que recebe um terreno e retorna uma string com o caminho que o Rei Gelado deve seguir para chegar ao ponto mais alto da sua ilha. A string deve ter as direções que o Rei Gelado deve seguir, na ordem em que ele as segue, separadas por "-" e finalizando com a string "FIM".

Por exemplo, se o terreno for:

`5 4 3`
`2 1 0`
`3 2 1`

...e o Rei Gelado começar na posição (1, 1) (que é o ponto no centro do terreno), a função deve retornar a string "CIMA-ESQUERDA-FIM", pois o Rei Gelado vai primeiro para CIMA (0,1), depois a ESQUERDA (0,0) e para por aí, terminando a string com FIM.   

Inicialmente, defina o tipo Terreno como um mapa de altitudes (contendo as dimensões do terreno e as altitudes de cada ponto) e o tipo Posicao, que representa uma posição no terreno e possui dois atributos do tipo inteiro: linha e coluna.  

Em seguida, implemente a função rumoAoTopo(), que recebe um terreno e a posição inicial do Rei Gelado, e retorna uma string com o caminho que ele deve seguir para chegar ao ponto mais alto da ilha.
 
OBS: Como o Rei Gelado se encontra em uma ilha, você pode assumir que a altitude de sua posição inicial é sempre maior ou igual a 0. Além disso, o terreno sempre terá pelo menos uma linha e uma coluna, ou seja, não há terrenos vazios.
*/
struct Terreno{
    int linha, coluna;
    int terreno[1000][1000];
};

struct Posicao{
    int linhaP;
    int colunaP;
};

string rumoAoTopo(Terreno const &ter, Posicao ponto){
    string a ="";
    string b = "";
    Posicao posicaoPro;
    int viAlto = ter.terreno[ponto.linhaP][ponto.colunaP];

    if((ponto.linhaP - 1 >= 0 &&  ter.linha) && (ter.terreno[ponto.linhaP][ponto.colunaP]  < ter.terreno[ponto.linhaP - 1][ponto.colunaP])){
        b = "CIMA-";
        viAlto = ter.terreno[ponto.linhaP - 1][ponto.colunaP];
        posicaoPro = {ponto.linhaP - 1, ponto.colunaP};
    }
    
    if((ponto.colunaP - 1  >= 0) && (ter.terreno[ponto.linhaP][ponto.colunaP]  < ter.terreno[ponto.linhaP][ponto.colunaP - 1]) && ter.terreno[ponto.linhaP][ponto.colunaP - 1] >= viAlto){
        b = "ESQUERDA-";
        viAlto = ter.terreno[ponto.linhaP][ponto.colunaP - 1];
        posicaoPro = {ponto.linhaP, ponto.colunaP - 1};
    }

    if((ponto.colunaP + 1 < ter.linha) && (ter.terreno[ponto.linhaP][ponto.colunaP] < ter.terreno[ponto.linhaP][ponto.colunaP + 1]) &&  ter.terreno[ponto.linhaP][ponto.colunaP + 1] >= viAlto){
        b = "DIREITA-";
        viAlto = ter.terreno[ponto.linhaP + 1][ponto.colunaP];
        posicaoPro = {ponto.linhaP, ponto.colunaP + 1};
    }

    if (ponto.linhaP + 1  < ter.linha && ter.terreno[ponto.linhaP][ponto.colunaP] < ter.terreno[ponto.linhaP + 1][ponto.colunaP] && ter.terreno[ponto.linhaP + 1][ponto.colunaP] >= viAlto){
        b = "BAIXO-";
        viAlto = ter.terreno[ponto.linhaP + 1][ponto.colunaP];
        posicaoPro = {ponto.linhaP + 1, ponto.colunaP};
    }
     if(ter.terreno[ponto.linhaP][ponto.colunaP] == viAlto){
        return a + "FIM";
     }
     else{
        a += b;
        return a + rumoAoTopo(ter, posicaoPro);
     }
    return a;

}
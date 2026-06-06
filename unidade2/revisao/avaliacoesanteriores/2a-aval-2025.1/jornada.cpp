/*
## Jornada

No jogo "Gelado", que você começou a desenvolver anteriormente, uma nova tarefa lhe foi passada. No jogo, um dos personagens deve realizar uma jornada épica, desbravando pântanos, desertos e geleiras, ao cruzar todo o terreno do jogo. Só que o personagem é corajoso, mas não é bobo! Se ele precisa cruzar todo o terreno, ele vai escolher o trajeto de menor esforço possível.  

Nessa jornada, o personagem terá algumas restrições. Ele só pode cruzar o terreno em linha reta, seja na horizontal ou na vertical. Ou seja, se ele começar a jornada na linha de índice 2, ele deve atravessar todas as colunas da linha 2, da primeira (de índice 0) até a última. O mesmo serve para ocaso dele começar a jornada em uma coluna. Se ele começar na coluna de índice 3, ele deve atravessar todas as linhas da coluna 3, da primeira (de índice 0) até a última.

Além disso, para escolher qual o trajeto de menor esforço, ele precisa conhecer o tipo de terreno que está atravessando. Ele pode atravessar 4 tipos de terrenos: pântano, planície, deserto e geleira. Cada um desses tipos vai ter um custo associado ao esforço de atravessá-lo. Atravessar um pântano tem custo 2, uma planície tem custo 1, um deserto tem 3 e uma geleira 4.  

O esforço de um trajeto é definido como a soma dos custos de atravessar cada ponto do terreno (considerando o tipo de terreno) mais o custo associado às diferenças de altitude entre dois pontos consecutivos (afinal, subir e descer montanhas cansa).  

Por exemplo, digamos que o terreno seja definido por um mapa 4x5 com as seguintes altitudes e tipos de terreno (onde P representa pântano, L planície, D deserto e G geleira):

`2 0 1 2 3 P P L L G`
`2 1 0 2 5 P L P L G`
`0 1 2 3 4 P D D G G`
`1 2 0 1 2 P D L L D`

Se a jornada for realizada na linha 0, o esforço de cada trajeto será calculado pelo custo das subidas e descidas:

|2 - 0| = 2
|0 - 1| = 1
|1 - 2| = 1
|2 - 3| = 1
total = 5

... mais o custo de atravessar os tipos de terreno:

`2 (pântano) + 2 (pântano) + 1 (planície) + 1 (planície) + 4 (geleira) = 10`
  
Assim, o esforço total da jornada na linha 0 será 5 (custo das altitudes) + 10 (custo dos tipos de terreno) = 15.

Na sua tarefa, você deve definir um tipo chamado TipoTerreno, capaz de representar os quatro tipos de terreno (pântano, planície, deserto e geleira) e um tipo chamado Terreno, que contém as dimensões do terreno (profundidade e largura), bem como as altitudes e os tipos de terreno de cada ponto (usando TipoTerreno). Esse tipo deve ter a capacidade de representar terrenos com até 500x500 pontos.

Em seguida, você deve implementar uma função chamada menor_jornada(), que recebe um terreno e retorna o menor esforço que o personagem pode fazer para realizar a jornada, seja na horizontal ou na vertical.

OBS: O terreno sempre terá pelo menos uma linha e uma coluna, ou seja, não há terrenos vazios. Além disso, sabe-se que uma jornada nunca terá esforço maior que 1000000.

DICA: Quebre o problema em problemas menores! Por exemplo, você pode quebrar no subproblema de calcular o esforço de uma linha ou de uma coluna. Crie funções para isso, teste se elas funcionam e depois use essas funções no problema principal.
*/
enum TipoTerreno{
    PLANICIE = 1, 
    PANTANO, 
    DESERTO,
    GELEIRA
};

struct Terreno{
    int linha; 
    int coluna;
    int altitude[500][500];
    TipoTerreno tipoTerreno[500][500];
};

int abs(int a){
    if (a < 0) return -a;
    else return a;
 }

void esforcoTerreno(Terreno const &tTerreno, int linha, int coluna,int somaDosT[]){
    int k = 0;

    //pegar soma das linhas. 
    for(int i = 0; i < linha; i++){
        somaDosT[k] = 0;
        for(int j = 0; j < coluna; j++){
            somaDosT[k] += (int) tTerreno.tipoTerreno[i][j];
        }
        k++;//atenção aqui
    }

    //pegar somas das colunas.
    for(int i = 0; i < coluna; i++){
        somaDosT[k] = 0;
        for(int j = 0; j < linha; j++){
            somaDosT[k] += (int) tTerreno.tipoTerreno[j][i];
        }
        k++;
    }
    // ate LINHAS array contera a soma das linha DPS de LINHAS e ANTES de coluna array tera a soma das colunas.   
}

void esforcoAltitude(Terreno const &pTerreno, int linha, int coluna, int somaDasAltitudes[]){
    int k = 0;

    //soma do esforco atrealdo as altitudes na linha
    for(int i = 0; i < linha; i++){
        somaDasAltitudes[k] = 0;
        for(int j = 0; j < coluna - 1; j++){
            somaDasAltitudes[k] += abs(pTerreno.altitude[i][j] - pTerreno.altitude[i][j + 1]);
        }
        k++;
    }
    

    for(int i = 0; i < coluna; i++){
        somaDasAltitudes[k] = 0;
        for(int j = 0; j < linha - 1; j++){
            somaDasAltitudes[k] +=  abs(pTerreno.altitude[j][i] - pTerreno.altitude[j + 1][i]);
        }
        k++;
    }
}

int menor_jornada(Terreno const &ter){
    int linhaT = ter.linha;
    int colunaT = ter.coluna;
    int esforcoTerrenos[linhaT + colunaT];    
    int esforcoAltitudes[linhaT + colunaT];
    int res = esforcoAltitudes[1] + esforcoTerrenos[1];

    esforcoTerreno(ter, linhaT, colunaT, esforcoTerrenos);
    esforcoAltitude(ter, linhaT, colunaT, esforcoAltitudes);

    int k = linhaT + colunaT;
    for(int i = 0; i < k; i++){
        if(res > esforcoAltitudes[i] + esforcoTerrenos[i])
            res = esforcoAltitudes[i] + esforcoTerrenos[i];   
    }    
        return res;
    }



#include <bits/stdc++.h>
using namespace std;
/*
Escreva seus tipos e funções neste arquivo.
*/
enum Notas{
    DO, 
    DO_SUSTENIDO, 
    RE, 
    RE_SUSTENIDO, 
    MI, 
    FA, 
    FA_SUSTENIDO, 
    SOL, 
    SOL_SUSTENIDO, 
    LA,
    LA_SUSTENIDO, 
    SI
};

struct Acorde{
    int num_notas;
    Notas notas[10];
};

struct SequenciaAcordes{
    int num_acordes;
    Acorde acordes[10];
};

Acorde graus (int grau){
    
    if(grau == 1){
        Acorde aGraus = {3,{DO, MI, SOL}};
        return aGraus;
    }
    if(grau == 2){
        Acorde aGraus = {3,{RE, FA, LA}};
        return aGraus;
    }
    if(grau == 3){
        Acorde aGraus = {3,{MI, SOL, SI}};
        return aGraus;
    }
    if(grau == 4){
        Acorde aGraus = {3,{FA, LA, DO}};
        return aGraus;
    }
    if(grau == 5){
        Acorde aGraus = {3,{SOL, SI, RE}};
        return aGraus;
    }
    if(grau == 6){
        Acorde aGraus = {3,{LA, DO, MI}};
        return aGraus;
    }
    if(grau == 7){
        Acorde aGraus = {3,{SI, RE, FA}};
        return aGraus;
    }

    Acorde bGraus{0, {DO, DO, DO}};
    return bGraus;

}

bool isMaior(Acorde acordeM){

    if(acordeM.num_notas!= 3){
        return false;
    }

    int tercaM = (acordeM.notas[1] - acordeM.notas[0] + 12) % 12;
    int quintaM = (acordeM.notas[2]  - acordeM.notas[0] + 12) % 12;
    
    return (tercaM == 4 && quintaM == 7);
}

void mudarTonalidade(SequenciaAcordes &sAcordes, Notas nota){
    
    int distanciaA = (nota  + 12) % 12;
    
    for(int i = 0; i < sAcordes.num_acordes; i++){
        for(int j = 0; j < sAcordes.acordes[i].num_notas; j++){
           sAcordes.acordes[i].notas[j] =(Notas)((sAcordes.acordes[i].notas[j] + distanciaA) % 12);
    }
    }
}

SequenciaAcordes gerarProgressao(string progressao, Notas nota){
    int nmrAcorde = 0;
    SequenciaAcordes sequenciaP = {4};
    
    for(int i = 0; i < progressao.size(); i++){
        if(progressao[i] != '-'){
            sequenciaP.acordes[nmrAcorde] = graus((int)progressao[i] - '0'); //OBTER VALOR REAL DE UM NUMERO     
            nmrAcorde++;
        }
    }
    mudarTonalidade(sequenciaP, nota);
    return sequenciaP;
}



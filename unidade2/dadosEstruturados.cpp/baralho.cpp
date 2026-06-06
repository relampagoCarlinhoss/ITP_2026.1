#include <bits/stdc++.h>
using namespace std;

enum Valor{
    AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI
};

enum Naipe{
    OUROS, COPAS, ESPADAS, PAUS
};

struct Carta{
    Valor valor;
    Naipe carta;
};

struct Cartas{
    int quantidade;
    Carta cartas[52];   
};

bool verificaCarta(const Cartas &mao){
    for(int i = 0; i < mao.quantidade -2; i++){
        Carta maoAtual = mao.cartas[i];
        Carta maoProxima = mao.cartas[i + 1];
        Carta maoProxP = mao.cartas[i+2];
        
        bool emSequencia;
        bool sNaipe = maoAtual.carta == maoProxima.carta && maoAtual.carta == maoProxP.carta;

        if(maoAtual.valor == DAMA){
            emSequencia = (maoProxima.valor == REI) && (maoProxP.valor == AS);
        }
        else{
            emSequencia = (maoAtual.valor == maoProxima.valor - 1) && (maoAtual.valor == maoProxP.valor - 2);
        }
        if(emSequencia && sNaipe){
            return true;
        }
    }
    return false;
}

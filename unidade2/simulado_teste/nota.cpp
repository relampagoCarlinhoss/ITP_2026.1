#include <bits/stdc++.h>
using namespace std;

enum Notas{
    DO, DO_SUSTENIDO, RE, RE_SUSTENIDO, MI, FA, FA_SUSTENIDO, SOL, SOL_SUSTENIDO, LA, SI
};

struct Acorde{
    int qtdNotas;
    int notas[];
};

bool isMaior(Acorde acordeM){
    if(acordeM.qtdNotas != 3){
        return false;
    }
    else{
        if(acordeM.notas[0] > acordeM.notas[1] ? 
            acordeM.notas[0] % acordeM.notas[1] == 4: acordeM.notas[1] % acordeM.notas[0] == 4){
                if(acordeM.notas[0] > acordeM.notas[2] ?
                    acordeM.notas[0] % acordeM.notas[2] == 7: acordeM.notas[2] % acordeM.notas[0] == 7){
                    return true;
                }
            }
    }
    return false;
}
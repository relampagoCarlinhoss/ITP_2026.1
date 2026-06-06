#include <iostream>
class Elevador{
    int andarAtual;
    int capMax;
    int numDePessoas;
    int totalDeAndares;

    public:
    //construtores
    Elevador(int capMaxP, int totalDeAndaresP): capMax(capMaxP), totalDeAndares(totalDeAndaresP), 
            numDePessoas(0),andarAtual(0) {};

    //operações
    int consultaNumPessoas(){return numDePessoas;}
    int consultaAndarAtual(){return andarAtual;}
    
    bool sobe(){
        if(andarAtual < totalDeAndares){
            andarAtual++;
            return true;
        }
        return false;
    }

    bool desce(){
        if(andarAtual > 0){
            andarAtual--;
            return true;
        }
        return false;
    }

    bool entra(){
        if(numDePessoas < capMax){
            numDePessoas++;
            return true;
        }
        return false;
    }

    bool sai(){
        if(numDePessoas > 0){
            numDePessoas --;
            return true;
        }
        return false;
    }
};



#include <iostream>
#include <cmath>

enum TipoCarga{
   D = 0, R = 1, N, E
};


class Consumo{
   int diurno;
   int noturno;


   public:
       //construtor
       Consumo(int diurno = 0, int noturno = 0): diurno(diurno), noturno(noturno){}
       Consumo(const Consumo &coP){
        diurno = coP.diurno;
        noturno = coP.noturno; 
       }
       
       //operacoes

       int diferenca(){return std::abs(diurno - noturno);}
};


class Setor{
   std::string nome;
   TipoCarga carga;
   Consumo *histCons;
   int qtdConsumo = 0;
   int historico_max = 100;
  
   //construtor e destrutor
   public:
   Setor(std::string nome = "", TipoCarga carga = D): nome(nome),carga(carga){
       histCons = new Consumo[historico_max];
   }
   
   Setor(const Setor &setorP){
        nome = setorP.nome;
        carga = setorP.carga;
        qtdConsumo = setorP.qtdConsumo;
        historico_max = setorP.historico_max;

        histCons = new Consumo[historico_max];
        for(int i = 0; i < qtdConsumo; i++){
            histCons[i] = setorP.histCons[i];
        }
   }
  
    ~Setor(){delete[]histCons;}
    Setor& operator=(const Setor &setorP){
        if(this != &setorP){
            delete[]histCons;
            
            nome = setorP.nome;
            carga = setorP.carga;
            qtdConsumo = setorP.qtdConsumo;
            historico_max = setorP.historico_max;
            
            histCons = new Consumo [historico_max];
            for(int i = 0; i < qtdConsumo; i++){
                histCons[i] = setorP.histCons[i];
            }    
        }
        return *this;//objeto real.
    }

   //operacoes
   std::string getNome(){return nome;}
   TipoCarga getCarga() {return carga;}

   bool addCons(int diurnoP, int noturnoP){
        if(qtdConsumo >= historico_max){
            historico_max *= 2;
            Consumo *mHistCons = new Consumo[historico_max];
            
            for(int i = 0; i < qtdConsumo; i++){
                mHistCons[i] = histCons[i];
            }

            delete[]histCons; 
            histCons = mHistCons;
       }

        histCons[qtdConsumo] = Consumo{diurnoP, noturnoP};
        qtdConsumo++;
       return true;
   }


   int difCons(){
       int maiorVar = 0;
       for(int i = 0; i < qtdConsumo; i++){
           if(maiorVar < histCons[i].diferenca()){
               maiorVar = histCons[i].diferenca();
           }
       }
       return maiorVar;
   }
};

class GerenciaSetor{
    int qtdSetores = 0;
    int setores_max = 100;
    Setor *setor;
    
    public:
    //construtor
    GerenciaSetor(){
        setor = new Setor[setores_max];
    }
    
    GerenciaSetor(const GerenciaSetor &setorP){
        qtdSetores = setorP.qtdSetores;
        setores_max = setorP.setores_max;
        
        setor = new Setor[setores_max];
        for(int i = 0; i < qtdSetores; i++){
            setor[i] = setorP.setor[i];
        }
    }

    //destrutor
    ~GerenciaSetor(){delete[]setor;}

    GerenciaSetor& operator=(const GerenciaSetor &sP){
        if(this != &sP){
            delete[]setor;
            qtdSetores = sP.qtdSetores;
            setores_max = sP.setores_max;

            setor = new Setor[setores_max];
            for(int i = 0; i < qtdSetores; i++){
                setor[i] = sP.setor[i];
            }
        }
        return *this;
    }

    //operações
    Setor* getSetor(){return setor;}

    bool cadastrarSetor(std::string nomeP, TipoCarga tP){
        
        if(qtdSetores >= setores_max){
            setores_max *= 2;
            Setor *mSetor = new Setor[setores_max];

            for(int i = 0; i < qtdSetores; i++){
                mSetor[i] = setor[i];
            }

            delete[]setor;
            setor = mSetor;
        }

        setor[qtdSetores] = Setor{nomeP, tP};
        qtdSetores++;
        return true;
    }

    bool removerSetor(){
        qtdSetores--;
        return true;
    };

    std::string maiorDif(){
        std::string nomeR  = setor[0].getNome();
        int rDif =  setor[0].difCons()*(int)setor[0].getCarga();
        for(int i = 0; i < qtdSetores; i++){
            if(rDif < setor[i].difCons()*(int)setor[i].getCarga()){
                rDif = setor[i].difCons()*(int)setor[i].getCarga();
                nomeR = setor[i].getNome();
            }
        }
        return nomeR;
    }

    int acharSetor(std::string nomeP){
        for(int i = 0; i < qtdSetores; i++){
            if(setor[i].getNome() == nomeP){
                return i;
            }
        }
        return -1;
    }
    
};

int main(){
    int quantidadeSetor; 
    GerenciaSetor gerente;
    std::string nome;
    std::string carga;
    TipoCarga cargaR = D;

    std::cin >> quantidadeSetor;

    while(quantidadeSetor--){
        std::cin >> nome >> carga;

        if(carga[0] == 'R') cargaR = R;
        if(carga[0] == 'N') cargaR = N;
        if(carga[0] == 'E') cargaR = E;
    
        gerente.cadastrarSetor(nome, cargaR);
    }

    int diurno, noturno;
    while(std::cin >> nome >> diurno >> noturno){
       int indice = gerente.acharSetor(nome);
       if(indice != -1){ 
       Setor *setorL = gerente.getSetor();
       setorL[gerente.acharSetor(nome)].addCons(diurno, noturno);
       }}

    std::cout << gerente.maiorDif() << "\n";

   return 0;
}


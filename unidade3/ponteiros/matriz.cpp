#include <iostream>

class Matriz{
    int linha;
    int coluna;
    int *m;

    public:
    
    //construtores
    Matriz(int linhaP, int colunaP){
        m = new int[linhaP*colunaP];
        linha = linhaP;
        coluna = colunaP;
        for(int i = 0; i < linhaP; i++){
            for(int j = 0; j < colunaP; j++){
                m[i* colunaP + j] = 0;
            }
        }
    }

    ~Matriz(){
        delete[] m;
    }

    //operações 
    int consultarCelula(int linhaP,int colunaP){
        return m[linhaP*coluna + colunaP];
    }

    bool alterarValor(int linhaP, int colunaP, int n){
        m[linhaP*coluna + colunaP] = n;
        return true;
    }

    void exibirMatriz(){
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                std::cout << m[i*coluna + j] << " ";
            }
            std::cout << "\n";
        }
    }

    bool mutiplica(int k){
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                m[i*coluna + j] *= k;
            }
        }
        return true;
    }

    Matriz transposta(){
        Matriz t(coluna, linha);
        int linhaT = coluna;
        int colunaT = linha;
        for(int i = 0; i < linhaT; i++){
            for(int j = 0; j < colunaT; j++){
                t.alterarValor(i, j, m[coluna*j + i]);
            }
        }
        return t;
    }
};
int main(){
    Matriz m(2,3);
    m.alterarValor(0,0, 2);
    m.alterarValor(0,1,4);
    m.alterarValor(1,0,10);
    m.alterarValor(1,1,4);
    m.alterarValor(1,2,25);
    m.alterarValor(1,2,200);
    m.exibirMatriz();
    Matriz mT = m.transposta();
    mT.exibirMatriz();


    return 0;
}
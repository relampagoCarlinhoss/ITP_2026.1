#include <iostream>

class Vector{
    int qtdElementos = 0;
    int tamanho;
    int *vector;

    public:
    //construtor
    Vector(int tamanhoT){
        vector = new int[tamanhoT];
        tamanho = tamanhoT;
    }
    
    ~Vector(){
        delete []vector;
    }
    
    //operações
    int qtdElementosM(){return qtdElementos;}
    int consultaTamanho(){return tamanho;}

    bool add(int elemento){
        if(qtdElementos < tamanho){
            vector[qtdElementos] = elemento;
            qtdElementos++;
            return true; 
        }
        return false;
    }

    bool remover(){
        if(qtdElementos > 0){
            qtdElementos--;
            return true;
        }

        return false;
    }

    int consultarEl(int n){
        return vector[n];
    }
};

int main(){
    std::cout << "adicionar elementos:" << "\n";
    Vector v(10);
    v.add(2);
    v.add(3);
    v.add(100);
    v.add(1882);
    v.remover();
    std:: cout << "tamanho: " << v.consultaTamanho() << "\n"; 
    std:: cout <<"quantidade de elementos: " << v.qtdElementosM() << "\n";
    std:: cout << "elemento: " << v.consultarEl(0) << "\n";



    return 0;
}
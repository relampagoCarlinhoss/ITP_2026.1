#include <iostream>

class Cidade{
    std :: string nome;
    int maxTemp;
    int minTemp;

    public:
    //construtores
    Cidade(std :: string const & nome = " ", int minTemp = 0, int maxTemp = 0):nome(nome), minTemp(minTemp),
    maxTemp(maxTemp){}
    
    Cidade(Cidade const & cidade){
        nome = cidade.getNome();
        maxTemp = cidade.getMax();
        minTemp = cidade.getMin();
    }

    //getters
    std :: string getNome() const {return nome;}
    int getMax() const {return maxTemp;}
    int getMin() const {return minTemp;}
    
    //amplitude
    int calcAmplitude(){
        int amplitude = maxTemp - minTemp;
        return amplitude;
    }
};

Cidade maiorAmplitude(Cidade cidades[], int n){
    int maiorAmplitude = 0;
    Cidade cidadeMaior; 
    for(int i = 0; i < n; i++){
        if(cidades[i].calcAmplitude () > maiorAmplitude){
            maiorAmplitude = cidades[i].calcAmplitude();
            cidadeMaior = cidades[i];
        }
    }   
    return cidadeMaior;
}

int main(){
    int n;
    std :: cin >> n;

    Cidade cidades[n];
    for(int i = 0; i < n; i++){
        std :: string nome;
        int min;
        int max;
        std :: cin >> nome >> min >> max;
        cidades[i] ={nome, min, max};
    }

    maiorAmplitude(cidades, n);
    Cidade cidadeIm = maiorAmplitude(cidades, n);
    std :: cout << cidadeIm.getNome() ;
    return 0;
}

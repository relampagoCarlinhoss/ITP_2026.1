#include <iostream>
using namespace std;

int main(){
    int qtdTipos, qtdPacotes, qtdPacotesCam;
    int sobras = 0;
    bool carregouP = false;
    cin >> qtdTipos >> qtdPacotes;

    int tipos[qtdTipos], pacotes[qtdPacotes], caminhao[qtdPacotes];
    for(int i = 0; i < qtdTipos; i++)cin >> tipos[i];
    for(int i = 0; i < qtdPacotes; i++)cin >> pacotes[i];

    bool marcador[qtdPacotes] = {false};
    bool sobrou = false;

    do{
        carregouP = false;
        int caminhaoAt = qtdTipos - 1;
        int capacidade = tipos[caminhaoAt];
        int tipoI = caminhaoAt;
        qtdPacotesCam = 0;
        
        for(int i = 0; i < qtdPacotes; i++){
            if(marcador[i] == false and pacotes[i] <= capacidade){
                capacidade -= pacotes[i];
                marcador[i] = true;
                caminhao[qtdPacotesCam] = i;
                qtdPacotesCam++;
                carregouP = true;
            }}

            if(capacidade > 0 && carregouP == true){
                for(int i = 0; i < qtdTipos; i++){
                    if(tipos[caminhaoAt] - capacidade <= tipos[i]){
                        tipoI = i;
                        break;
                    }
                }
            }

        if(carregouP){
        cout << tipoI << ":" << " ";}

        for(int i = 0; i < qtdPacotesCam; i++){
                cout << caminhao[i] << " ";
        }   
        cout << " \n";
    }while(carregouP);

    bool temSobras = false;
    for(int i = 0; i < qtdPacotes; i++) {
        if(marcador[i] == false) {
            temSobras = true;
            cout << i << " ";
    }
}
    if(temSobras) cout << endl;
    return 0;
}
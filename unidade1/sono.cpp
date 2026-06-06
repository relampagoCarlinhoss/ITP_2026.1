#include <iostream>
using namespace std;

int main(){
    int horaD, minD, horaA, minA,inicio, fim, sono;

    cin>>horaD>>minD>>horaA>>minA;

    inicio=horaD*60+minD;
    fim=horaA*60+minA;
    sono=fim-inicio;
    if(sono<=0){
        sono+=24*60;
    }
    cout<<sono<<endl;

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int num, primeiro, ultimo;

    cin>>num;

    ultimo=num%10;
    primeiro=num;
    while(primeiro >= 10){
        primeiro = primeiro / 10;
    }
    if(ultimo == primeiro){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
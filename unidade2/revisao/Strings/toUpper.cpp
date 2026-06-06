#include <iostream>
using namespace std;

void toUpaperr (string &a){
    for(int i = 0; i < a.size(); i++){
        
        if(a[i] >= 97 && a[i] <= 122){
        a[i] = a[i] - 32;}
    }
}

int main(){    
    string a= "eu ainda vou a praia nesse fim de semana";
    toUpaperr(a);
    cout << a;


    return 0;
}
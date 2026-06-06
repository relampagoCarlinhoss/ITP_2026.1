#include <iostream>
using namespace std;

string hexadecimal(int rgb[3]){
    string resp ="#";

    for(int i = 0; i < 3; i++){
        int quociente = 0, resto;
        int valor = rgb[i];
        do{
            quociente = valor / 16;
            resto = valor % 16;

            if(resto >= 10){
                resp += resto - 10 + 'A';
                valor = quociente;
                continue;
            }
            
            resp += to_string(resto);
            valor = quociente;
        } while(quociente != 0);
         
        if(rgb[i] < 16){
                resp += "0";
            }
    }

    for(int i = 1; i < resp.size() - 1;){
        char temp = resp[i];
        resp[i] = resp[i + 1];
        resp[i + 1] = temp; 
        i +=2;
    }

    return resp;
}

int main(){
    int rgb[3] = {34, 78, 90};
    cout << hexadecimal(rgb);


    return 0;
}
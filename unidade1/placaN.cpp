#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool placa = true;
    if(s.size() == 8 && s[3] == '-'){
        string s1 = s.substr(0,4);
        string s2 = s.substr(4,4);
        for(int i = 0; i < 4; i++){
            if(i == 3){
                continue;
            }
            if((s1[i] < 65 || s1[i] > 90) || (s2[i] < 48) || (s2[i] > 57)){
                placa = false;
                break;
            }
        }
        if(placa){
            cout << "SIM";
        }
        else{
            cout << "NAO";
        }
    }
    else{
        cout << "NAO";
    }



    return 0;
}
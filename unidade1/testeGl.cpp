#include <iostream>
#include <string> 
using namespace std;

int main(){
    string s, texto;
    string mp = "";
    int cont = 0;
    int tL = 0;
    int mL= 0;

    do{
        getline(cin,s);
        texto= s + "\n";
        tL += s.size();
        cont++;

        if(mL < s.size() && s != ""){
            mL =(int) s.size();
        }
        string sT;
        for(int i = 0; i < s.size(); i++){
            if(s[0] != ' ' || (s[i-1] == ' ') && (s[i] != ' ')){
                int pos = s.find(' ', i);
                if(pos == string :: npos){
                    int tam = s.size() - i;
                    sT = s.substr(i, tam);
                }
                else{
                    int tam = pos - i;
                    sT = s.substr(i,tam);
                }
            }
            if(mp.size() < sT.size()){
                mp = sT;
            } 
    }
    }while(s != "");
    int tamP = mp.size();
    cout << mL << " "<< tL/cont<< " " << mp << " " << tamP << " ";

return 0;
}
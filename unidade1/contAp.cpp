#include <iostream> 
#include <string>
using namespace std;

int main(){
    string t, p;
    int contP = 0;

    getline(cin, t);
    cin >> p;

    for(int i = 0; i < t.size(); i++){
        if((i == 0 && t[i] != ' ') || (i > 0 && t[i-1] == ' ' && t[i] != ' ')){
            
            if(t[i] == p[0]){

                int posE = (int) t.find_first_of(' ', i);
                int tam;
                if(posE == (int) string :: npos){
                    tam = (int)t.size()-i;
                }else{
                    tam = posE - i;
                }
                string pT = t.substr(i, tam);
                
                if(pT == p){
                    contP++;
                }
            }
        }
    }
    cout << contP;

    return 0;
}

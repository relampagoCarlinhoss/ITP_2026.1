#include <iostream>
using namespace std;

int main(){
    string a;
    bool ehPlaca = true;
    cin >> a;
    
    if(a.size()){
        for(int i = 0; i < a.size(); i++){
            if(i < 3){
                if(a[i] < 65 || a[i] > 90){
                    ehPlaca = false; 
                    break;
                }
            }

            if(i == 3){
                if(a[i] != '-'){
                    ehPlaca = false;
                    break;
                }
            }
            
            if(i > 3){
                if(a[i] < 48 || a[i] > 57){
                    ehPlaca = false;
                }
            }
        }
    }

    else ehPlaca = false;
    
    (ehPlaca) ? (cout << "é placa"): (cout << "não é placa");
    return 0;
}
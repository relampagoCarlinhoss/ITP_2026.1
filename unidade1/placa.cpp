#include <iostream>
using namespace std;

int main(){
    string p;
    int ver = 0;
    int l = false;
    cin >> p;

    
    if( p.size() == 8){
        if(p[3] == '-'){
            for(int i = 0; i < p.size() - 4; i++ )
            {
                if(p[i] >= 60 && p[i] <= 90){
                    if(p[i+4] < 60 || p[i+4] > 90) l = 1;
            }                
            }
    }}
    else if(p.size() == 7){
        if((p[3] < 60 || p[3] > 90) && (p[4] >= 60 && p[4] <= 90)){
            for(int j = 0; j < p.size()- 4; j++)
            {
            if(p[j])    

            }
        }
    }
    return 0;
}
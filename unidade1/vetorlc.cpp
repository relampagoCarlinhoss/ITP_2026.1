#include <iostream>
using namespace std;

int main(){
    int n,legal;
    
    cin >> n;

    int vetor[n];

    for(int i=0;i<n;i++){
        cin >> vetor[i];
    }

    for(int cont=n; cont>=0; cont--){
        if(((vetor[cont]-vetor[cont-1])%2) == 0){
            legal++;
        }
       }
    if(legal==n-1){
        cout<<"legal";
    }
    else{
        cout<<"chato";
    }
    cout<<legal;
    cout<<n;
    return 0;
}
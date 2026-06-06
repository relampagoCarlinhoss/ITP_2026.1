#include <iostream>
using namespace std;

int main(){
    int id1,id2,id3;
    int maior, menor,camila;
    
    cin>>id1>>id2>>id3;

    if(id1>=id2 && id1>=id3){
        maior=id1;
    }else if(id2>=id1 && id2>=id3){
        maior=id2;
    }else{
        maior=id3;
    }
    if(id1<=id2 && id1<=id3){
        menor=id1;
    }else if(id2<=id1 && id2<=id3){
        menor=id2;
    }else if(id3<=id2 && id3<=id1){
        menor=id3;
    }
    camila=(id1+id2+id3)-(maior+menor);
    cout<<camila<<endl;

    return 0;
}

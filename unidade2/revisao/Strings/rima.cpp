#include <iostream>
using namespace std;

int main(){
    string a = "eu ainda nao fui a escola";
    string b = "vou pedir esa";

    for(int i = 0; i < a.size(); i++){
        a[i] = toupper(a[i]);
    }
    for(int i = 0; i < b.size(); i++){
        b[i] = toupper(b[i]);
    }

    if(a[a.size() -1] == b[b.size() - 1] && a[a.size() - 2] == b[b.size() - 2 ]){
        cout << "rima";
    }
    else{
        cout << "não rima";
    }


    return 0;
}
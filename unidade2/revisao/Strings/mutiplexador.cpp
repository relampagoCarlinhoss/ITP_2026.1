#include <iostream>
using namespace std;

int main(){
    string a;
    string b;
    cin >> a >> b;
    
    if(a > b){
        string temp = a;
        a = b;
        b = temp;
    }

     int ponteiro = 0;
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
        cout << b[i];
        ponteiro++;
    }

    for(int i = ponteiro; i < b.size(); i++){
        cout << b[i];
    }
    cout << "\n";
    return 0;
}
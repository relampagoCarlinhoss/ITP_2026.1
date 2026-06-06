#include <iostream>
using namespace std;

int main(){
    string a;
    int qtdVogais = 0;
    cin >> a;

    for(int i = 0;i < a.size(); i++){
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' ||
            a[i] == 'a'|| a[i] == 'e' ||a[i] == 'i' ||a[i] == 'o' ||a[i] == 'u'){
                qtdVogais++;
            }
    }
    cout << qtdVogais;
    return 0;
}
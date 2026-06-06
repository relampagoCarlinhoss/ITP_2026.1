#include <iostream>
using namespace std;

int main(){
    string a ="";
    int delta;
    
    getline(cin, a);
    cin >> delta;
     
    for(int i = 0; i < a.size(); i++){
        int deltalex = ((a[i]  - 97 + delta) % 26) + 97;
        a[i] = deltalex;
    }

    cout << a;
    return 0;
}
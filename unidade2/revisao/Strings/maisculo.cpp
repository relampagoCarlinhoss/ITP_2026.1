#include <iostream>
using namespace std;

int main(){
    string a;
    getline(cin, a);

    for(int i = 0; i != string :: npos;){
        a[a.find_first_not_of(" ", i)] = toupper(a[a.find_first_not_of(" ", i)]);
        i = a.find_first_of(" ", a.find_first_not_of(" ", i));
    }

    cout << a;


    return 0;
}
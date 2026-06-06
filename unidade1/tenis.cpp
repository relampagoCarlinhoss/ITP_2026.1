#include <iostream>
using namespace std;

int main(){
    int clas = 0;
    string res;

    for(int i = 0; i < 6; i++)
    {
        cin >> res;
    
        if(res == "V" || res == "v")
        {
            clas++;
        }
    }

    if(clas >= 5) cout << 1;
    else if(clas == 4 || clas == 3) cout << 2;
    else if(clas < 3 && clas >= 1) cout << 3;
    else if(clas == 0) cout << -1;
    return 0;
}
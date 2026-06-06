#include <iostream>
using namespace std;

    int main(){
    int n, mov;
    char pos;

    cin >> n >> pos;

    for(int i = 0; i < n; i++)
    {
        cin >> mov;
        if(mov == 1)
        {
            if(pos == 'A') pos = 'B';
            else if(pos == 'B') pos = 'A';
        } 
        if(mov == 2)
        {
            if(pos == 'B') pos ='C';
            else if(pos == 'C') pos = 'B';
        }
        if(mov == 3)
        {
            if(pos == 'A') pos = 'C';
            else if (pos == 'C') pos = 'A';
        }
    }
    cout << pos;
    return 0;
}
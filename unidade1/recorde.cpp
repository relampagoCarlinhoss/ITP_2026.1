#include <iostream>
using namespace std;

int main(){
    int ra, rm, ro;
    
    cin >> ra >> rm >> ro;

    if(ra < rm && ra < ro)
    {
        cout << "RM" << "\n" << "RO";
    }
    else if(ra < rm && ra >= ro)
    {
        cout << "RM" << "\n" << "*";
    }
    else if(ra >= rm && ra < ro)
    {
        cout << "*" << "\n" << "RO";
    }
    else if (ra >= rm && ra >= ro)
    {
        cout << "*" << "\n" << "*";    
    }
    return 0;
}
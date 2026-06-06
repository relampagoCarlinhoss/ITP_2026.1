#include <iostream>
using namespace std;

int main(){
   string a;
   string b = "";
   int i = 0;

   getline(cin, a);
   
    while(i != string :: npos){
        b += tolower(a[a.find_first_not_of(" ", i)]);
        i = a.find_first_of(" ",a.find_first_not_of(" ", i)); 
   }

   cout << b << " ";
    return 0;
}
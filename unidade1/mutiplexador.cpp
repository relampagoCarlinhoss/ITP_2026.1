#include <iostream>
#include <string> 
using namespace std;

int main(){
    string s1, s2;
    
    cin >> s1 >> s2;

    if(s1.size() == s2.size()){
        for(int i = 0; i < s1.size(); i++){
            cout << s1[i] << s2[i];
        }
    }
    
    else if(s1.size() < s2.size()){
        int cont = 0;
        for(int i = 0; i < s1.size(); i++){
            cout << s1[i] << s2[i];
            cont++;
        }
        for(int i = cont; i < s2.size(); i++){
            cout << s2[i];
        }
    }

    else if(s2.size() < s1.size()){
        int cont = 0;
        for(int i = 0; i < s2.size(); i++){
            cout << s1[i] << s2[i];
            cont++;
        }

        for(int i = cont; i < s1.size(); i++){
            cout << s1[i];
        }
    }
    


    return 0;
}
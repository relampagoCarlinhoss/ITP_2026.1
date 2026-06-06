#include <iostream>
 using namespace std;

 int main(){
    int k;
    while(scanf("%d", &k) != EOF){
        int s;
        int v = 0;
        while(k--){ scanf("%d", &s); v+=s;}
        printf("%d \n", v);
 }
    return 0;}
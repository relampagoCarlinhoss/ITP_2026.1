#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    printf("%s", (n >= 3 && a>=1 && b >=1 && c>= 1 && a+b+c >= n)? 
    "YES": "NO");
    return 0;
}

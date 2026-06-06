#include <iostream>
using namespace std;

bool hasIntersection(int t1, int a[], int t2, int b[]){
    for(int i = 0; i < t1; i++){
        for(int j = 0; j < t2; j++){
            if(a[i] == b[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
int a[] = {5, 3, 5, 6};
int b[] ={4, 1, 2, 0, 6};
int c[] = {10, 11, 124, 454};
hasIntersection(4, a, 5, b) ? cout << "existe": cout << "nao existe";

    return 0;
}
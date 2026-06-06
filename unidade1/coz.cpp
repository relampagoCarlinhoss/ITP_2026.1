#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int vetI[m], vetT[n];

    for(int i = 0; i < m; i++) cin >> vetI[i];
    for(int i = 0; i < n; i++) cin >> vetT[i];

    int k = 0;
    int qR = 0;

    for(int i = 0; i < n; i++){
        if(vetT[i] == vetI[k]){
            k++;
        }

        if(k == m){
            qR++;
            k=0;
        }
        }
        cout << qR << "\n";
}
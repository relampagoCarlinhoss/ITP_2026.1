#include <iostream>

using namespace std;

int main() {
    int K, L;

    cin >> K >> L;

    K--; 
    L--;

    if (K / 2 == L / 2) {
        cout << "oitavas";
    } 
    else if (K / 4 == L / 4) {
        cout << "quartas";
    } 
    else if (K / 8 == L / 8) {
        cout << "semifinal";
    } 
    else {
        cout << "final";}

    return 0;
}
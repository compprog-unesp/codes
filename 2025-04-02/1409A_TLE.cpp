// Uma possivel solução é ir incrementando o número a operação por operação.
// No entanto, se a diferença for grande, pode dar TLE.

#include <iostream>

using namespace std; 

int main() {
    int t; cin >> t;

    for (; t > 0; t--) {
        int a, b, operacoes = 0;
        cin >> a >> b;
        
        if (a > b)
            swap(a, b);

        while (a != b) {
            if (b - a > 10)
                a += 10;
            else
                a += b - a;

            operacoes++;
        }

        cout << operacoes << "\n";
    }


    return 0;
}
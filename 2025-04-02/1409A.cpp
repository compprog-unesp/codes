// A forma mais eficiente é sempre ir adicionando 10.
// Dividindo a distância entre a e b por 10, temos a quantidade de operações se for um múltiplo de 10.
// Se não for, basta somar um.

#include <iostream>

using namespace std; 

int main() {
    int t; cin >> t;

    for (; t > 0; t--) {
        int a, b, operacoes = 0;
        cin >> a >> b;
        
        operacoes = abs(b - a) / 10;

        if (abs(b - a) % 10 != 0)
            operacoes++;

        cout << operacoes << "\n";
    }


    return 0;
}
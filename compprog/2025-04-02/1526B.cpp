// pode-se mostrar que os numeros da sequencia 1111, 11111, 111111,...
// podem ser formados apenas usando uma combinacao linear de 11 e 111.
// Assim, o problema se reduz a verificar se o n pode ser decomponsto em combinacao de 11 e 111

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    for (; t > 0; t--) {
        long int n;
        cin >> n;
 
        // pode-se provar que qualquer numero maior que m*n - n - m pode ser escrito como a*n + b*n
        if (n > 11 * 111 - 11 - 111) {
            cout << "YES\n";
            continue;
        }
 
        // verifica se é combinacao linear de 11 e 111
        bool possivel = false;
        while (n > 0) {
            if (n % 11 == 0 || n % 111 == 0) {
                possivel = true;
                break;
            }
            n -= 111; 
        }
 
        if (possivel)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}
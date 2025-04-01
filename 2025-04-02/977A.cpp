#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // realiza as k operacoes
    while (k > 0) {
        k--;

        if (n - (n / 10) * 10 == 0) // checa se o ultimo digito eh 0
            n /= 10;
        else
            n -= 1;
    }

    cout << n;
}
// A solução é feita iterando ano a ano até que a seja maior do que b.

#include <iostream>

using namespace std;

int main() {
    int a, b, anos = 0;
    cin >> a >> b;

    while (a <= b) {
        a *= 3;
        b *= 2;
        anos ++;
    }

    cout << anos;

    return 0;
}
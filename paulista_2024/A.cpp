#include <iostream>

using namespace std;

int main() {
    int w, a, b, c;
    cin >> w >> a >> b >> c;

    if (w >= a + b + c)
        cout << "S";
    else cout << "N";

    return 0;
}
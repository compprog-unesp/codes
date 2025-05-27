#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "?R-SP" || s == "B?-SP" || s == "BR?SP")
        cout << "S";
    else if (s == "BR-?P" || s == "BR-S?")
        cout << "T";
    else
        cout << "N";


    return 0;
}
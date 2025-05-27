
#include <iostream>
 
#define sim() { std::cout << "S\n"; continue; }
 
using namespace std;
 
int main() {
    int n; cin >> n;
 
    for (; n > 0; n--) {
        int x, y;
        cin >> x >> y;
 
        if (x >= 0 && y >= 0 && x + y <= 100) sim();
        if (x >= 0 && x <= 100 && y <= 0 && y >= -100) sim();
        if (x >= 100 && x <= 200 && y <= 0 && y >= -100 && (x-100) - y <= 100) sim();
 
        if (x <= 0 && x >= -100 && y >= 0 && y <= 100) sim();
        if (x <= 0 && x >= -100 && y <= 0 && y >= -100 && -x - y <= 100) sim();
        if (x <= -100 && x >= -200 && y >= 0 && y <= 100 && -(x+100) + y <= 100) sim()
 
        cout << "N\n";
        continue;
    }
 
    return 0;
}
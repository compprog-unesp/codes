#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    vector<stack<int>> columns(2, stack<int>());
    int k, x;
 
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (i < 2)
                columns[i].push(x);
        }
    }
 
    if (n != 2) {
        cout << "S";
        return 0;
    }
 
    while (!columns[0].empty()) {
        if (columns[0].top() == 1)
            break;
        columns[0].pop();
        columns[1].push(2);
    }
    while (!columns[1].empty()) {
        if (columns[1].top() == 2)
            break;
        columns[1].pop();
        columns[0].push(1);
    }
 
    while (!columns[0].empty()) {
        if (columns[0].top() == 2) {
            cout << "N";
            return 0;
        }
        columns[0].pop();
    }
    while (!columns[1].empty()) {
        if (columns[1].top() == 1) {
            cout << "N";
            return 0;
        }
        columns[1].pop();
    }
 
    cout << "S";
 
    return 0;
}
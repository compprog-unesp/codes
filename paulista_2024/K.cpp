#include <iostream>
#include <vector>

using namespace std;

const long long mod = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> c(n+1, 0);
    c[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (i == k)
                continue;
            else
                c[j] = (c[j] + c[j-i]) % mod;

    cout << c[n] % mod;

    return 0;
}
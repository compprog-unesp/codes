#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes, ocurrences, indices(1000010, 0);
vector<vector<int>> divisors(1000010, vector<int>());

void generate_primes() {
    vector<bool> is_prime(1000010, true);
    primes.push_back(1);

    for (int i = 2; i < 1000010; i++) {
        if (!is_prime[i]) continue;
        for (int j = i+i; j < 1000010; j += i) {
            divisors[j].push_back(i);
            is_prime[j] = false;
        }
        divisors[i].push_back(i);
        primes.push_back(i);
        indices[i] = primes.size()-1;
    }
}

void update(int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        ocurrences[pos] += val;
        return;
    }

    int m = (ini + fim) / 2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);

    ocurrences[pos] = max(ocurrences[e], ocurrences[d]);
}

int main() {
    int n;
    cin >> n;

    vector<bool> used(1000010, false);
    generate_primes();
    ocurrences.assign(primes.size()*4, 0);

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bool change = false;
        for (auto d : divisors[x]) {
            change = true;
            if (used[x]) 
                update(1, 1, primes.size(), indices[d], -1);
            else
                update(1, 1, primes.size(), indices[d], 1);
        }

        if (change)
            if (used[x]) used[x] = false;
            else used[x] = true;

        cout << ocurrences[1] << "\n";
    }

    return 0;
}
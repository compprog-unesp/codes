#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparator(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> max(n, 0);
    vector<pair<int,int>> product;
    int x, v;
    int res = 0, current = 0, current_max = 0, j = 0;

    for (int i = 0; i < n; i++) {
        cin >> x >> v;
        product.push_back({x, v});
    }

    sort(product.begin(), product.end(), comparator);

     for (int i = 0; i < n; i++) {
        current += product[i].second;
        while (product[i].first - product[j].first > d) {
            current -= product[j].second;
            j++;
        }

        if (i == 0) {
            res = product[i].second;
            max[i] = product[i].second;
            current_max = product[i].second;
            continue;
        } 
        current_max = std::max(current_max, current);
        max[i] = current_max;

        if (j == 0)
            res = max[i];
        else
            res = std::max(res, current + max[j-1]);
    }
    
    cout << res;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, p, s;
    cin >> n >> m >> p >> s;
    
    int x, y;
    vector<pair<int, int>> excecoes;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cin >> y;
        excecoes.push_back({x-1, y-1});
    }

    bool valido;
    int res = 0, pao, pao_salsicha, completo;
    int total_combinacoes_extras = pow(2, n-p-s);
    for (int i = 0; i < p; i++) {
        pao = (1 << i);
        for (int j = p; j < p+s; j++) {
            pao_salsicha =  pao | (1 << j);

            for (int k = 0; k < total_combinacoes_extras; k++) {
                valido = true;
                completo = pao_salsicha | (k << p+s);
                for (auto e : excecoes)
                    if (completo & (1 << e.first) && completo & (1 << e.second)) {
                        valido = false; break;
                    }
                if (valido) res++;
            }
        }
    }

    cout << res;

    return 0;
}
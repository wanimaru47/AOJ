#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;

int main ()
{
    int n, m, s, g1, g2;
    while (cin >> n >> m >> s >> g1 >> g2, n + m + s + g1 + g2) {
        vector<vector<int> > d(n + 1, vector<int>(n + 1, INF));
        for (int i = 0; i <= n; i++) {
            d[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int gx, gy, c;
            cin >> gx >> gy >> c;
            d[gx][gy] = c;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int  k = 1; k <= n; k++) {
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }

        int res = INF;
        for (int i = 1; i <= n; i++) {
            res = min(res, d[s][i] + d[i][g1] + d[i][g2]);
        }

        cout << res << endl;
    }

    return 0;
}

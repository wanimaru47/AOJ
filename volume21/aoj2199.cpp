#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;

int main ()
{
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<vector<int> > dp(n + 1, vector<int>(256, INF));

        vector<int> c(m);
        vector<int> x(n);

        for (auto &i : c) cin >> i;
        for (auto &i : x) cin >> i;

        dp[0][128] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < m; k++) {
                    int pre = j + c[k];
                    if (pre > 255) pre = 255;
                    if (pre < 0) pre = 0;

                    dp[i][pre] = min(dp[i][pre], dp[i-1][j] + (pre - x[i-1]) * (pre - x[i-1]));
                }
            }
        }

        int res = INF;
        for (int i = 0; i < 256; i++) {
            res = min(res, dp[n][i]);
        }

        cout << res << endl;
    }

    return 0;
}

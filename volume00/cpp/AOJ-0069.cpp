#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef queue<P> Q;

int main ()
{
    int N, m, g, D;
    while (cin >> N, N) {
        cin >> m >> g >> D;
        vector<string> v (D+1, "0000000000");
        for (int i = 0; i < D; i++) {
            cin >> v[i];
        }

        int d[D+1][N];
        for (int i = 0; i <= D; i++) for (int j = 0; j < N; j++) d[i][j] = 0;

        int y = m - 1;
        for (int i = 0; i <= D; i++) {
            d[i][y] = 5;
            if (0 < y && v[i][y-1] == '1') {
                y -= 1;
            } else if (y < N - 1 && v[i][y] == '1') {
                y += 1;
            }
        }
        if (g-1 == y) {
            cout << 0 << endl;
            continue;
        }

        y = g - 1;
        for (int i = D; i >= 0; i--) {
            d[i][y] = 6;
            if (0 < y && v[i][y-1] == '1') {
                y -= 1;
            } else if (y < N - 1 && v[i][y] == '1') {
                y += 1;
            }
        }

        for (int i = 0; i <= D; i++) {
            for (int j = 0; j < N; j++) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i <= D; i++) {
            for (int j = 0; j < N; j++) {
                if (d[i][j] == 5) {
                    if (j == 0 && v[i][j+1] != '1' && d[i][j+1] == 6) {
                        cout << i+1 << " " << j+1 << endl;
                        goto escape;
                    }
                    if (j == N - 1 && v[i][j-2] != '1' && d[i][j-1] == 6) {
                        cout << i+1 << " " << j << endl;
                        goto escape;
                    }
                    if (v[i][j] != '1' && v[i][j-1] != 'a') {
                        if (d[i][j+1] == 6 && ((j+1 < N-1 && v[i][j+1] == '0') || j+1 == N-1)) {
                            cout << i+1 << " " << j+1 << endl;
                            goto escape;
                        }
                        if (d[i][j-1] == 6 && ((j-2 > 0 && v[i][j-1] == '0') || j-2 == 0)) {
                            cout << i+1 << " " << j << endl;
                        }
                    }
                }
            }
        }
        
        cout << 1 << endl;
    escape:;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> P;

const int INF = 1 << 28;
const int dx[] = {0, 1,-1, 1, 0,-1};
const int dy[] = {1, 0,-1, 1,-1, 0};

int main ()
{
    int t, n;
    while (cin >> t >> n, (n || t)) {
        int d[222][222];
        bool w[222][222];
        for (int i = 0; i < 222; i++) {
            for (int j = 0; j < 222; j++) {
                d[i][j] = INF;
                w[i][j] = true;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            d[t1 + 60][t2 + 60] = -1;
        }
        
        int x, y;
        cin >> x >> y;
        d[x + 60][y + 60] = 0;
        w[x + 60][y + 60] = false;
        queue<P> q;
        q.push(P(x + 60, y + 60));

        int count = 1;
        while (q.size()) {
            P p = q.front();
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if (0 <= nx && nx < 222 && 0 <= ny && ny < 222 && d[nx][ny] != -1) {
                    if (d[nx][ny] > d[p.first][p.second] + 1 && d[p.first][p.second] < t) {
                        if (w[nx][ny]) count++, w[nx][ny] = false;
                        q.push(P(nx,ny));
                        d[nx][ny] = d[p.first][p.second] + 1;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}

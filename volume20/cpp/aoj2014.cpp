#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int w = 0, b = 0;
int n, m;
char d[50][50];
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

void bfs (int x, int y, char s, char t, char u) {
    queue<P> q;
    q.push(P(x,y));

    while (q.size()) {
        P p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i], y = p.second + dy[i];
            if (0 <= x && x < m && 0 <= y && y < n) {
                if (d[x][y] == '.') {
                    if (s == 'W') w++;
                    else b++;
                    q.push(P(x,y));
                    d[x][y] = t;
                } else if (d[x][y] == u) {
                    if (s == 'W') b--;
                    else w--;
                    q.push(P(x,y));
                    d[x][y] = t;
                }
            }
        }
    }
}

int main ()
{
    while (cin >> n >> m, (n || m)) {
        for (int i = 0; i < m; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] == 'W') {
                    bfs(i, j, 'W', '*', '@');
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] == 'B') {
                    bfs(i, j, 'B', '@', '*');
                }
            }
        }
        cout << b << " " << w << endl;
        w = b = 0;
    }

    return 0;
}

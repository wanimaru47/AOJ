#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int n, m;
int b, w;
char d[55][55];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void bfs (int x, int y, char s) {
    queue<P> q;
    q.push(P(x,y));

    while (q.size()) {
        P p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            x = p.first + dx[i], y = p.second + dy[i];
            if (0 <= x && x < n && 0 <= y && y < m) {
                if (d[x][y] == '.') {
                    d[x][y] = (s == 'W') ? '*' : '@';
                    q.push(P(x,y));
                    s == 'W' ? w++ : b++;
                } else if (s == 'B' && d[x][y] == '*') {
                    w--;
                    q.push(P(x,y));
                    d[x][y] = '@';
                }
            }
        }
    }
}

int main ()
{
    while (cin >> m >> n, (n || m)) {
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        b = w = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (d[i][j] == 'W') {
                    bfs (i, j, 'W');
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (d[i][j] == 'B') {
                    bfs (i, j, 'B');
                }
            }
        }

        /*
        for (int i = 0; i < m; i++) {
            cout << d[i] << endl;
        }
        */

        cout << b << " " << w << endl;
    }
    
    return 0;
}

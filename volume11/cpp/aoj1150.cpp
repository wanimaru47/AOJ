#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef pair<int,PP> PPP;

const int INF = 1 << 28;

int dlx[] = { 1, 1, 1, 1, 1, 2, 2, 2, 3}; 
int drx[] = {-1,-1,-1,-1,-1,-2,-2,-2,-3};
int dy[]  = {-2,-1, 0, 1, 2,-1, 0, 1, 0};


int main ()
{
    int h, w;
    while (cin >> w >> h, h + w) {
        vector<vector<int> > field(h, vector<int>(w, INF));
        vector<P> s;
        vector<P> t;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char str;
                cin >> str;
                if ('0' <= str && str <= '9') {
                    field[i][j] = (int)(str - '0');
                } else if (str == 'T') {
                    field[i][j] = 0;
                    t.push_back(P(i,j));
                } else if (str == 'S') {
                    field[i][j] = 0;
                    s.push_back(P(i,j));
                } else if (str == 'X') {
                    field[i][j] = INF;
                }
            }
        }

        priority_queue<PPP, vector<PPP>, greater<PPP> > que;
        vector<vector<vector<int> > > d(2, vector<vector<int> >(h, vector<int>(w, INF)));
        for (int i = 0; i < s.size(); i++) {
            que.push(PPP(0, PP(0, P(s[i])) ) );
            que.push(PPP(0, PP(1, P(s[i])) ) );
            d[0][s[i].first][s[i].second] = 0;
            d[1][s[i].first][s[i].second] = 0;
        }

        while (que.size()) {
            PPP ppp = que.top(); que.pop();
            int cost = ppp.first;
            PP pp = ppp.second;
            int dir = pp.first;
            int y = pp.second.first;
            int x = pp.second.second;

            if (d[dir][y][x] < cost) continue;

            for (int i = 0; i < 9; i++) {
                int nx = x, ny = dy[i] + y;
                nx += dir == 1 ? dlx[i] : drx[i];
                if (0 <= nx && nx < w && 0 <= ny && ny < h && field[ny][nx] != INF) {
                    if (d[1 - dir][ny][nx] > cost + field[ny][nx]) {
                        d[1 - dir][ny][nx] = cost + field[ny][nx];
                        que.push(PPP(d[1 - dir][ny][nx], PP(1 - dir, P(ny, nx) ) ) );
                    }
                }
            }
        }

        int res = INF;
        for (int i = 0; i < t.size(); i++) {
            int y = t[i].first;
            int x = t[i].second;
            res = min(res, d[0][y][x]);
            res = min(res, d[1][y][x]);
        }

        cout << (INF == res ? -1 : res) << endl;
    }

    return 0;
}

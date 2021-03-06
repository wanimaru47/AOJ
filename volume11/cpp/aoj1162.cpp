#include <bits/stdc++.h>
using namespace std;

const double dINF = 1e11; 

typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef pair<double,PP> PPP;

int main ()
{
    int n, m;
    while (cin >> n >> m, n + m) {
        int s, g;
        cin >> s >> g;
        vector<vector<PP> > e(n + 1);

        for (int i = 0; i < m; i++) {
            int sx, sy, d, c;
            cin >> sx >> sy >> d >> c;
            e[sx].push_back(PP(sy, P(d, c) ));
            e[sy].push_back(PP(sx, P(d, c) ));
        }

        priority_queue<PPP, vector<PPP>, greater<PPP> > pq;
//        vector<vector<double> > dp(31, vector<double>(n + 1, dINF));
        vector<vector<vector<double> > > dp(31, vector<vector<double> >(n + 1, vector<double>(n + 1, dINF)));
        // dp[0][0][s] = 0.;
        double res = dINF;
        
        for (int j = 0; j < e[s].size(); j++) {
            int dir = e[s][j].first;
            int dis = e[s][j].second.first;
            int limit = e[s][j].second.second;

            dp[1][s][dir] = (double)dis;
            pq.push(PPP((double)dis, PP(1, P(dir, s)) ));
        }

        while (pq.size()) {
            PPP ppp = pq.top(); pq.pop();
            double cost = ppp.first;
            int v = ppp.second.first;
            int now = ppp.second.second.first;
            int pre = ppp.second.second.second;

            if (dp[v][pre][now] < cost) continue;
            // if (now == g && v == 1 && dp) break;

            // cout << now << " " << pre  << " " << v << endl;
            
            for (int i = 0; i < e[now].size(); i++) {
                if (e[now][i].first == pre) continue;
                
                for (int j = -1; j <= 1; j++) {
                    if (v + j <=  0 || v + j > e[now][i].second.second) continue;
                    double cost_ = cost + (double)e[now][i].second.first / (double)(v + j);
                    int to_ = e[now][i].first;
                    if (dp[v + j][now][to_] > cost_) {
                        dp[v + j][now][to_] = cost_;
                        pq.push(PPP(cost_, PP(v + j, P(to_, now))) );
                        if (to_ == g && v + j == 1)
                        {
                            res = min(res, cost_);
                            // cout << "DBG > cost : " << cost_ << " v : " << v + j << " to : " << to_ << endl;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            res = min(res, dp[1][i][g]);
        }
        // if (dp[1][g] == dINF) cout << "unreachable" << endl;
        // else printf("%.12f\n", dp[1][g]);
        if (res == dINF) cout << "unreachable" << endl;
        else printf("%.12f\n", res);
    }

    return 0;
}

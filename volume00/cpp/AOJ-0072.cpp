#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

typedef pair<int,int> P;

const int MAX = 10000;
const int INF = 999999;

int V;
int m;

int prim (vector<vector<P> > G) {
    set<int> used;
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i = 0; i < V; i++) {
        used.insert(i);
    }
    int res = 0;
    int v = 0;
    while (!used.empty()) {
        for (auto i : G[v])   que.push(i);
        P p;
        while (used.find(que.top().second) == used.end() || que.top().second == v) {
            que.pop();
            if (que.empty()) break;
        }
        if (que.empty()) break;
        used.erase(used.find(v));
        p = que.top(); que.pop();
        v = p.second;
        res += p.first;
    }

    return res;
}

int main ()
{
    while (cin >> V, V) {
        cin >> m;
        vector<vector<P> >  G(V);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d,%d,%d", &a, &b, &c);
            c /= 100;
            G[a].push_back(P(c,b));
            G[b].push_back(P(c,a));
        }

        cout << prim(G) - V + 1 << endl;
    }

    return 0;
}

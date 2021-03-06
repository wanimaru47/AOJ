#include <bits/stdc++.h>
using namespace std;

map<char,int> m;
vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
set<char> Top;
string S;

// int dfs (int n, int sum, vector<int> v) {
int dfs (int n, int sum, vector<int> &v) {
    if (n == m.size()) return sum == 0;

    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0 && Top.find(S[n]) != Top.end()) continue;
        int tmp = v[i];
        // auto v_(v);
        v.erase(v.begin() + i);
        // v_.erase(v_.begin() + i);
        // res += dfs (n + 1, sum + (m[S[n]] * tmp), v_);
        res += dfs (n + 1, sum + (m[S[n]] * tmp), v);
        v.insert(v.begin() + i, tmp);
    }

    return res;
}

int main ()
{
    int n;
    while (cin >> n, n) {
        //vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        set<char> s;
        m.clear();
        Top.clear();
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            int k = 1;
            if (str.size() > 1) Top.insert(str[0]);
            for (int j = str.size()-1, k = 1; j >= 0; j--, k *= 10) {
                s.insert(str[j]);
                if (m.find(str[j]) == m.end()) {
                    if (i == n - 1) m[str[j]] = -k;
                    else m[str[j]] = k;
                } else {
                    if (i == n - 1) m[str[j]] -= k;
                    else m[str[j]] += k;
                }
            }
        }

        S = "";
        for (auto i : s) {
            S += i;
        }

        cout << dfs(0, 0, v) << endl;
    }

    return 0;
}
    

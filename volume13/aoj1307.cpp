#include <bits/stdc++.h>
using namespace std;
  
void solve(int N) {
    // int v[444];
    // memset(v, 0, sizeof(v));
    vector<int> v(401);
    int max_len = 0;
    for (int i = 0; i < N * (N-1) / 2; i++) {
        int j; cin >> j; v[j]++;
        max_len = max(max_len, j);
    }
  
    set<vector<int>> ans;
    for (int i = 0; i < (1<<(N-2)); i++) {
        vector<int> s;
        // int count[444];
        // memcpy(count, v, 444);
        auto count = v;
        bool flag = false;
  
        s.push_back(0);
  
        int t = max_len;
        int j = 0;
        while (t) {
            if (!count[t]) {
                t--;
                continue;
            }
  
            int position = (i & (1 << j)) ? max_len - t : t;
            for (auto k : s) {
                int dist = abs(k - position);
                if (count[dist]) count[dist]--;
                else {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            s.push_back(position);
            j++;
        }
        if (flag) continue;
        sort(s.begin(), s.end());
        vector<int> ad;
        for (int i = 0; i < N-1; i++) ad.push_back(s[i+1] - s[i]);
        ans.insert(ad);
        reverse(ad.begin(), ad.end());
        ans.insert(ad);
    }
  
    for (auto avec: ans) {
        for (int i = 0; i < N-1; i++) {
            if (i < N-2) cout << avec[i] << " ";
            else cout << avec[i] << endl;
        }
    }
      
    cout << "-----" << endl;
}
  
int main() {
    int N;
    while (cin >> N, N) {
        solve(N);
    }
  
  
    return 0;
}

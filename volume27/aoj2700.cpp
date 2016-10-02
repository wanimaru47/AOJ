#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<string> vstr(N);
        for (auto& i : vstr) cin >> i;

        vector<string> cstr;
        int max_len = 0;
        for (auto str : vstr) {
            string s = "";
            s += str[0];

            string alf = "aiueo";
            for (int i = 1; i < str.size(); i++) {
                if (alf.find(str[i-1]) != string::npos) {
                    s += str[i];
                }
            }

            cstr.push_back(s);

            max_len = max(max_len, (int)s.size());
        }

        int ans = -1;

        for (int i = 1; i <= max_len; i++) {
            set<string> ss;
            for (auto s : cstr) {
                ss.insert(string(s.begin(), s.begin() + min(i, (int)s.size())));
            }

            if (ss.size() == N) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

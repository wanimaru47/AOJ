#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<string> ans;
string str;

void dfs (string &S, int C, int B) {
    if (C == str.size()) {
        ans.insert(S);
        return ;
    }

    if (~B & (1 << ('z' - 'a')) && str[C] == 'z') return ;
    if (str[C] == 'a') {
        if (~B & (1 << 1) ) {
            S[C] = 'b';
            dfs (S, C + 1, B | (1 << 1));
        }
        S[C] = 'a';
        dfs (S, C + 1, B | (1 << 0));
        
    } else if (B & (1 << (str[C] - 'a')) ) {
        if ('z' >= (str[C] + 1) && ~B & (1 << (str[C] - 'a' + 1)) ) {
            S[C] = (char)(str[C] + 1);
            dfs (S, C + 1, B | (1 << (str[C] + 1 - 'a')) );
        }
        S[C] = str[C];
        dfs (S, C + 1, B);
        
    } else {
        if ('z' >= (str[C] + 1) && ~B & (1 << (str[C] - 'a' + 1)) ) {
            S[C] = (char)(str[C] + 1);
            dfs (S, C + 1, B | (1 << (str[C] + 1 - 'a')) );
            
        } else
            return ;
    }
}

int main ()
{
    while (cin >> str, str != "#") {
        ans.clear();
        string tmp = str;
        dfs(tmp, 0, 0);
        int s = ans.size();
        cout << s << endl;

        int k = 0;
        if (0 < s && s <= 10) {
            for (auto i : ans) {
                cout << i << endl;
            }
        } else if (s > 10) {
            int k = 0;
            for (auto i : ans) {
                if (k == 5) break;
                cout << i << endl;
                k++;
            }
            auto ite = ans.end(); ite--; ite--; ite--; ite--; ite--;
            k = 0;
            while (k++ < 5) {
                cout << *ite << endl;
                ite++;
            }
        }
    }

    return 0;
}

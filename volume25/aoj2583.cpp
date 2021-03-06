#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n, n) {
        vector<string> v;
        vector<int> h;
        int hmax = 0;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            int count  = 0;
            while (str[count] == '.') count++;
            // count--;
            if (count > 0) str[--count] = '+';
            v.push_back(str);
            h.push_back(count);
            hmax = max(hmax, count);
        }


        for (int i = 0; i < hmax; i++) {
            for (int j = n - 1; j > 0; j--) {
                if (h[j] < i) continue;
                if (v[j][i] == '+' && v[j-1][i] == '.') {
                    j--;
                    while (v[j][i] == '.') {
                        v[j][i] = '|';
                        j--;
                    }
                    j++;
                } else if (v[j][i] == '.') {
                    v[j][i] = ' ';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << endl;
        }
    }

    return 0;
}

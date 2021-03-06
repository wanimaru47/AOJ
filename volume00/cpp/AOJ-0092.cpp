#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<string> V;
        while (n--) {
            string tmp;
            cin >> tmp;
            V.push_back(tmp);
        }
        n = V.size();
        vector<vector<int> > N(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n -1; j++) {
                if (V[i][j] == '.') N[i][j]++;
                if (V[i][j] == V[i][j+1] && V[i][j] == '.') {
                    N[i][j+1] += N[i][j];
                }
            }
            if (V[i][n-1] == '*') N[i][n-1] = 0;
            else N[i][n-1]++;
        }
        int res = 0;
        for (int i = 0; i < N.size(); i++) {
            for (int j = 0; j < N[i].size(); j++) {
                if (N[i][j] > res) {
                    int t = N[i][j];
                    bool flag = true;
                    for (int k = 0; k < t; k++) {
                        if (i + k >= n) {
                            flag = false;
                            break;
                        }
                        if (N[i+k][j] < t) {
                            t = N[i+k][j];
                        }
                    }
                    if (flag && res < t) {
                        res = t;
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}

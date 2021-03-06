#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int n, m;
    while (cin >> n >> m, (n || m)) {
        vector<int> v(n);
        int MAX = 0;
        for (auto &i : v) {
            cin >> i;
            MAX = max(MAX, i);
        }

        double res = 0.01;
        for (int i = 0; i < n - 1; i++) {
            res += ((double)v[i] / MAX) * ((double)(n - 1 - i) / (n - 1));
        }

        cout << res << endl;
    }

    return 0;
}

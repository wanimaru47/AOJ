#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<string> name(n);
        vector<int> price(n);
        vector<int> sold(n);
        vector<int> times(n);
        vector<int> m(n);
        vector<int> count(n);
        for (int i = 0; i < n; i++) {
            int a, b, c, d, e;
            cin >> name[i] >> price[i] >> a >> b >> c >> d >> e >> count[i] >> sold[i] >> m[i];
            times[i] = a + b + c + (d + e) * m[i]; 
        }

        vector<pair<double,string> > res;
        for (int i = 0; i < n; i++) {
            double p = (double)(m[i] * sold[i] * count[i]- price[i]) / (double)times[i];
            res.push_back(pair<double,string>(-p, name[i]));
        }

        sort(res.begin(), res.end());

        for (int i = 0; i < n; i++) {
            cout << res[i].second << endl;
        }
        cout << "#" << endl;
    }

    return 0;
}

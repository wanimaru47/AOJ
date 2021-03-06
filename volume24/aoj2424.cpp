#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main ()
{
    int q;
    cin >> q;
    while (q--) {
        int n, res = 0;
        cin >> n;
        set<int> t;
        while (n / 10) {
            t.insert(n);
            res++;
            int MAX = 0;
            int j = 1, k = 0;
            while (n) {
                k += j * (n % 10);
                n /= 10;
                MAX = max(MAX, k * n);
                j *= 10;
            }
            n = MAX;
            if (t.find(n) != t.end()) {
                res = -1;
                break;
            }
        }
        cout << res << endl;
    }

    return 0;
}

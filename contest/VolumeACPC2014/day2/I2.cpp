#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, q;
const int INF = 1 << 28;

int main ()
{
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    int sp = sqrt(n);
    for (int i = 0; i < n - (n % sp); i += sp) {
        sort(b.begin() + i, b.begin() + i + sp - 1);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        int res = INF;
        if (r - l <= sp * 3) {
            for (int j = l; j <= r; j++ ) {
                res = min (res, abs(d - a[j]));
            }
        } else {
            if (l % sp) {
                while (l % sp > 0 && l <= r) {res = min (res, abs(d - a[l])); l++;}
            }
            int lb, ub; lb = l - 1; ub = lb + sp ;
            while (ub <= r - (r % sp) - 1) {
                while (ub - lb > 1) {
                    int mid = (ub + lb) / 2;
                    if (b[mid] >= d) {
                        ub = mid;
                    } else {
                        lb = mid;
                    }
                }
                res = min (res, abs(d - b[ub]));
                ub += sp;
                lb += sp;
            }
            for (int j = r - (r % sp); j <= r; j++)
                res = min (res, abs(d - a[j]));
            
        }
        cout << res << endl;
    }

    return 0;
}

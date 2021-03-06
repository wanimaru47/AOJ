#include <iostream>
using namespace std;

const int INF = 999999999;
const int rot[] = {4, 1, 4, 1, 2, 1, 2, 1};

int main ()
{
    int n[8];
    while (cin >> n[0]) {
        for (int i = 1; i < 8; i++) cin >> n[i];
        int min_c = INF, min_n = INF;
        int res = 0;
        for (int i = 0; i < 8; i++) {
            int c = 0, num = 0;
            int LL = 10000000;
            for (int j = 0; j < 8; j++) {
                int k = (j + i) % 8;
                int t = n[j] - rot[k];
                if (t > 0) c += t;
                num += rot[k] * LL;
                LL /= 10;
            }
            if (min_c > c) {
                min_c = c;
                min_n = num;
                res = i;
            } else if (min_c == c && min_n > num) {
                min_n = num;
                res = i;
            }
        }
        for (int i = res; i < res + 7; i++) {
            cout << rot[i % 8] << " ";
        }
        cout << rot[(res + 7) % 8] << endl;
    }

    return 0;
}

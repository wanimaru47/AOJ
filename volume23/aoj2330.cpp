#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int res = 0;
    while (n > 1) {
        if (n == 2) {
            res++;
            break;
        }
        n = (n % 3) ? (n / 3) + 1 : (n / 3);
        res++;
    }
    cout << res << endl;
}

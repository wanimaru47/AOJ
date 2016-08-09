#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int count = 1;
    while (cin >> N, N) {
        cout << "Case " << count << ":" << endl;
        int dir = 1;
        vector<vector<int> > d(N, vector<int>(N));
        int x = 0, y = 0;
        for (int i = 0; i < N*N; i++) {
            d[x][y] = i+1;
            int nx = x - dir;
            int ny = y + dir;

            if (nx >= N) {
                nx = x;
                ny = y+1;
                dir *= -1;
            }

            if (ny >= N) {
                ny = y;
                nx = x+1;
                dir *= -1;
            }

            if (nx < 0) {
                if (ny >= N) nx++, ny--;
                else nx++;
                dir *= -1;
            }
            if (ny < 0) {
                if (nx >= N) ny++, nx--;
                else ny++;
                dir *= -1;
            }

            x = nx;
            y = ny;
        }

        for (auto i : d) {
            for (auto j : i) printf("%3d", j);
            cout << endl;
        }
        count++;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main ()
{
    int T, P, R;
    while (cin >> T >> P >> R, (R || P || T)) {
        vector<vector<int> > w(T, vector<int>(P, 0));
        vector<int> c(T, 0);
        vector<int> s(T, 0);

        while (R--) {
            int id_t, id_p, time;
            string message;
            cin >> id_t >> id_p >> time >> message;
            if (message == "CORRECT") {
                s[id_t - 1] += time + w[id_t - 1][id_p - 1] * 1200;
                c[id_t - 1] += 1;
            } else {
                w[id_t - 1][id_p - 1] += 1;
            }
        }

        set<pair<int,int> > *rank = new set<pair<int,int> >[P + 1];
        for (int i = 0; i < T; i++) {
            rank[c[i]].insert(pair<int,int>(s[i], i));
        }
        for (int i = P; i >= 0; i--) {
            if (rank[i].size() != 0) {
                for (auto j : rank[i]) {
                    cout << j.second + 1 << " " << i << " " << j.first << endl;
                }
            }
        }
        
        delete [] rank;
    }

    return 0;
}

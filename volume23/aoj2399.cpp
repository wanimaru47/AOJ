#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<set<int> > v(n, set<int>());
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            while (tmp--) {
                int tmpp;
                cin >> tmpp;
                v[i].insert(tmpp);
            }
        }

        set<int> more;
        int m;
        cin >> m;
        while (m--) {
            int tmp;
            cin >> tmp;
            more.insert(tmp);
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (more.size() <= v[i].size()) {
                int flag = true;
                for (auto j : more) {
                    if (v[i].find(j) == v[i].end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag) res.push_back(i+1);
            }
        }

        cout << (res.size() == 1 ? res[0] : -1) << endl;
    }

    return 0;
}

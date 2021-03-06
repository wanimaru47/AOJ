#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector <pair<int,int> > V;
    for (int i = 0; i <= n; i++) {
        V.push_back(pair<int,int>(0,i));
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        V[a].first += b;
    }
    sort(V.begin(), V.end());
    int i = 1;
    while (V[i].first != V[n].first) i++;
    cout << V[i].second << " " << V[i].first << endl;

    return 0;
}

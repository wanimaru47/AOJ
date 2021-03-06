#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    vector<vector<int> > V(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> V[i][j];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            V[i][j+1] += V[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            V[j+1][i] += V[j][i];
        }
    }

    int res = -100000000;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++) {
            for (int j = i+1; j <= n; j++) {
                for (int k = l+1; k <= n; k++) {
                    if ((V[j][k] - V[i][k]) - (V[j][l] - V[i][l]) > res)
                        res = (V[j][k] - V[i][k]) - (V[j][l] - V[i][l]);
                }
            }
        }
    }
    cout << res << endl;
    
    return 0;
}

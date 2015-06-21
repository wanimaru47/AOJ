#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
using namespace std;

typedef list<int> L;
typedef pair <int,int> P;
typedef vector<int> V;
typedef queue<int> Q;
typedef stack<int> S;
typedef map<string,int> M;

int main()
{
    int H, W;
    
    while (cin >> H >> W, H) {
        char d[H][W];
        int ansW, ansH, ans = 0;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> d[i][j];

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (d[i][j] == '.') {
                    ansH = 0;
                    ansW = 9999;
                    while (d[i + ansH][j] == '.' && i + ansH < H) {
                        int m = 0;
                        while (d[i + ansH][j + m] == '.' && j + m < W) m++;
                        ansW = min(ansW, m);
                        ansH++;
                        ans = max(ans, ansW * ansH);
                        /*
                        for (int k = 0; k < H; k++) {
                            for (int l = 0; l < W; l++) {
                                if (i <= k && k < i + ansH && j <= l && l < j + ansW)
                                    cout << "0";
                                else
                                    cout << d[k][l];
                            }
                            cout << endl;
                        }
                        cout << endl;
                        */
                    }
                        
                }
            }
        }
        cout << ans << endl;
    }
    
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int x1, y1, x2, y2;

bool dist(int nx, int ny) {
    if(1 >= abs(nx - x1) + abs(ny - y1)) return true;
    if(1 >= abs(nx - x2) + abs(ny - y2)) return true;
    return false;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    cin >> x1 >> y1 >> x2 >> y2;

    map<char,int> dx, dy;
    dx['U'] = -1, dy['U'] = 0;
    dx['D'] = 1, dy['D'] = 0;
    dx['L'] = 0, dy['L'] = -1;
    dx['R'] = 0, dy['R'] = 1;
    int res = 1 << 28;
    
    vector<vector<int>> d(H + 1, vector<int>(W + 1, 0));

    for(int i = 0; i < N; i++) {
        int sx, sy;
        cin >> sy >> sx;
        int times; cin >> times;
        string code; cin >> code;
        for (int j = 0; j < code.size(); j++) {
        }
    }
    cout << res << endl;

    return 0;
}
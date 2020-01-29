#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
int accs[501][501];
int r, c, k;
bool check(int y, int x) {
    for (int dx = -k; dx <= k; dx++) {
        int dy = k - abs(dx);
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= c || ny < 0 || ny >= r) return false;

        int need = dy * 2 + 1;
        if (accs[nx][ny + 1] < need) return false;
    }
    return true;
}
int main() {
    cin >> r >> c >> k;
    --k;
    vector<string> arr(r);
    rep(i, r) cin >> arr[i];
    for (int x = 0; x < c; x++) {
        for (int y = 0; y < r; y++) {
            accs[x][y + 1] = (arr[y][x] == 'o' ? accs[x][y] + 1 : 0);
        }
    }

    int ans = 0;
    rep(i, r) {
        rep(j, c) {
            if (check(i, j)) ans++;
        }
    }
    cout << ans << endl;
}

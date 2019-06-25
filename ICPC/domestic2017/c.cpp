#include <cstdio>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
int calc(int top, int buttom, int left, int right, vector<vector<int>> board) {
    int out_min = 1e6;

    for (int i = top; i <= buttom; i++) {
        for (int j = left; j <= right; j++) {
            if (i == top or i == buttom or j == left or j == right) {
                out_min = min(out_min, board[i][j]);
            }
        }
    }

    int ans = 0;
    for (int y = top; y <= buttom; y++) {
        for (int x = left; x <= right; x++) {
            if (y == top or y == buttom or x == left or x == right) {
                continue;
            }
            if (board[y][x] >= out_min) {
                return 0;
            }
            ans += out_min - board[y][x];
        }
    }
    return ans;
}
void solve(int d, int w) {
    vector<vector<int>> board(d, vector<int>(w));
    rep(y, d) rep(x, w) {
            cin >> board[y][x];

    }
    int ans = 0;
    rep(top, d - 2) {
        for (int buttom = top + 2; buttom < d; buttom++) {
            rep(left, w - 2) {
                for (int right = left + 2; right < w; right++) {
                    ans = max(ans, calc(top, buttom, left, right, board));
                }
            }
        }
    }
    cout << ans << endl;

}
int main() {
    while (true) {
        int d, w;
        cin >> d >> w;
        if (d == 0 and w == 0) break;
        solve(d, w);
    }
    return 0;
}

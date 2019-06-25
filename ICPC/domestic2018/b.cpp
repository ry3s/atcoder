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

void solve(int n, int m, int t, int p) {
    vector<vector<int>> board(1e3 + 10, vector<int>(1e3 + 10, 0)); // (x, y)
    rep(x, n) rep(y, m) {
        board[x][y] = 1;
    }
    int left = 0;
    int right = n;
    int top = m;
    int bottom = 0;
    rep(i, t) {
        int d, c;
        cin >> d >> c;
        if (d == 1) { // left

            for (int x = 0; x < c; x++) {
                for (int y = bottom; y < top; y++) {
                    board[left + c + x][y] += board[left + c - x -1][y];
                }
            }
            right = max(right, left + 2 * c);
            left = left + c;
        } else if (d == 2) { // bottom
            for (int y = 0; y < c; y++) {
                for (int x = left; x < right; x++) {
                    board[x][bottom + c + y] += board[x][bottom + c - y - 1];
                }
            }
            top = max(top, bottom + 2 * c);
            bottom = bottom + c;
        }
    }
    rep(i, p) {
        int x, y;
        cin >> x >> y;
        cout << board[left + x][bottom + y] << endl;
    }
}
int main() {
    while (true) {
        int n, m, t, p;
        cin >> n >> m >> t >> p;
        if (n == 0 and m == 0 and t == 0 and p == 0) break;
        solve(n, m, t, p);
    }
    return 0;
}

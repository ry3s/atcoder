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
using LL = long long int;
using ULL = unsigned long long int;

char table[9][9];
int win[9];
int lose[9];
int n;
int ans;
int max_game;
void dfs(int g, int x, int y, int win[9], int lose[9]) {
    cout << "(" << x << ", " << y << ")" << endl;
    int eq = (n - 1) / 2;
    if (x == n - 1 and y == n - 1) {
        bool ok = false;
        int t = win[0];
        int s = lose[0];
        rep(i, n) {
            if (win[i] == t and lose[i] == s) ok = true;
            else ok = false;
        }
        if (ok) ans++;
        return;
    }
    if (x == y) {
        dfs(g + 1, x, y + 1, win, lose);
        return;
    }
    int nx = x + (y == n - 1);
    int ny = (y == n - 1 ? 0 : y + 1);

    // if (g == max_game) { // finish
    //     if (table[x][y] == 'w' and win[x] == eq and lose[y] == eq) ans++;
    //     else if (table[x][y] == 'l' and win[y] == eq and lose[x] == eq) ans++;
    //     else if (win[x] + 1 == eq and lose[y] + 1 == eq) ans++;
    //     else if (win[y] + 1 == eq and lose[x] + 1 == eq) ans++;
    //}
    if (table[x][y] == '-') {
        cout << "???" << endl;
        //if (win[x] + 1 <= eq and lose[y] + 1 <= eq) {
            win[x]++;
            lose[y]++;
            dfs(g + 1, nx, ny, win, lose);
            win[x]--;
            lose[y]--;
//        }
//        if (win[y] + 1 <= eq and lose[x] + 1 <= eq) {
            win[y]++;
            lose[x]++;
            dfs(g + 1, nx, ny, win, lose);
            win[y]--;
            lose[x]--;
//        }
    } else if (table[x][y] == 'l') {
        cout << "@@@" << endl;
        //if (win[y] <= eq and lose[x] <= eq) {
            dfs(g + 1, nx, ny, win, lose);
            //}
    } else if (table[x][y] == 'w') {
        cout << "$$$" << endl;
//        if (win[x] <= eq and lose[y] <= eq) {
            dfs(g + 1, nx, ny, win, lose);
            //      }
    }
}
void solve(int m) {
    rep(i, n) rep(j, n) {
        table[i][j] = '-';
    }
    rep(i, n) {
        win[i] = lose[i] = 0;
    }
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        table[x][y] = 'w';
        table[y][x] = 'l';
        win[x]++;
        lose[y]++;
    }
    rep(i, n) rep(j, n) {
        cout << table[i][j] << " ";
        if (j == n - 1) cout << endl;
    }
    max_game = 1;
    for (int i = 1; i < n; i++) {
        max_game *= i;
    }
    ans = 0;
    dfs(0, 0, 0, win, lose);
    cout << ans << endl;
}
int main() {
    while (true) {

        cin >> n;
        if (n == 0) break;

        int m;
        cin >> m;
        solve(m);
    }
}

#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
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
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int> > yx(h, vector<int>(w, 0));
    int startx, starty;
    rep(i, h) {
        rep(j, w) {
            char ch;
            cin x>> ch;
            if (ch == 'S') {
                yx[i][j] = -1;
                starty = i;
                startx = j;
            } else if (ch == 'X') {
                yx[i][j] = -2;
            } else if (ch == '.') {
                yx[i][j] = 0;
            } else {
                yx[i][j] = ch - '0';
            }
        }
    }
    queue<pair<int, int> > qu;
    qu.push(make_pair(starty, startx));
    vector<vector<bool> > visited(h, vector<bool>(w, false));
    int current_hp = 1;
    while (not qu.empty()) {
        auto p = qu.front();
        qu.pop();
        int y = p.first;
        int x = p.second;
        if (yx[y][x] != -1 and yx[y][x] != -2 and yx[y][x] != 0
            and yx[y][x] <= current_hp) {
            current_hp++;
        }
        rep(i, 4) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if ()

        }

    }

}

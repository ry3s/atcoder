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

tuple<int, int, int> count_stat(const string &s) {
    int n = s.length();
    int win = 0;
    int lose = 0;
    int draw = 0;
    rep(x, n) {
        switch (s[x]) {
        case 'w':
            win++;
            break;
        case 'l':
            lose++;
            break;
        case '?':
            draw++;
            break;
        default:
            break;
        }
    }
    return make_tuple(win, lose, draw);

}

bool check_stat(const string &s) {
    int win, lose;
    tie(win, lose, ignore) = count_stat(s);
    int k = (s.length() - 1) / 2;
    return (win <= k) and (lose <= k);
}
int bit_count(int bits) {
    int num = 0;
    for (; bits != 0; bits &= bits - 1) {
        num++;
    }
    return num;
}
void solve(int n, int m) {
    vector<string> a(n, string(n, '?'));
    rep(z, n) {
        a[z][z] = '-';
    }
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = 'w';
        a[y][x] = 'l';
    }
    LL cnt = 0;
    function<void (int)> go =
        [&](int y) {
            if (y == n) {
                cnt++;
                return;
            }

            for (int z = y; z < n; z++) {
                if (not check_stat(a[y])) {
                    return;
                }
            }
            int win, lose, draw;
            tie(win, lose, draw) = count_stat(a[y]);
            int k = (n - 1) / 2 - win;

            for (int s = 0; s < (1 << draw); s++) {
                if (bit_count(s) == k) {
                    int i = 0;
                    for (int x = y + 1; x < n; x++) {
                        if (a[y][x] == '?') {
                            a[x][y] = (s & (1 << i)) ? 'l' : 'w';
                            i++;
                        }
                    }

                    go(y + 1);
                    for (int x = y + 1; x < n; x++) {
                        if (a[y][x] == '?') {
                            a[x][y] = '?';
                        }
                    }
                }
            }
        };
    go(0);
    cout << cnt << endl;

}
int main() {
    while (true) {
        int n, m;
        cin >> n;
        if (n  == 0) break;
        cin >> m;
        solve(n, m);
    }
    return 0;
}

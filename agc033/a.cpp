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

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<bool> > xy(h, vector<bool>(w, false));
    bitset<1000000> is_black;
    is_black.set();
    rep(i, h) {
        rep(j, w) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                xy[i][j] = true;
            } else {
                is_black.reset(i * h + j);
            }
        }
    }
    auto current_gen = xy;
    auto next_gen = xy;

    LL cnt = 0;
    while (1) {
        cnt++;
        rep(i, h) {
            rep(j, w) {
                if (current_gen[i][j] == true) {
                    if (i - 1 >= 0) {
                        next_gen[i - 1][j] = true;
                        is_black.set((i - 1) * h + j);
                    }
                    if (i + 1 < h) {
                        next_gen[i + 1][j] = true;
                        is_black.set((i + 1) * h + j);
                    }
                    if (j - 1 >= 0) {
                        next_gen[i][j - 1] = true;
                        is_black.set(i * h + j - 1);
                    }
                    if (j + 1 < w) {
                        next_gen[i][j + 1] = true;
                        is_black.set(i * h + j + 1);
                    }
                }
            }
        }
        if (is_black.all()) {
            cout << cnt << endl;
            return 0;
        }

        current_gen = next_gen;
    }
    return 0;
}

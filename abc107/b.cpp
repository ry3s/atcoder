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
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
    }
    set<int> row, column;

    rep(i, h) {
        bool ok = true;
        rep(j, w) {
            if (a[i][j] == '#') ok = false;
        }
        if (ok) row.insert(i);
    }
    rep(j, w) {
        bool ok = true;
        rep(i, h) {
            if (a[i][j] == '#') ok = false;
        }
        if (ok) column.insert(j);
    }

    rep(i, h) {
        if (row.find(i) != row.end()) continue;
        rep(j, w) {
            if (column.find(j) != column.end()) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}

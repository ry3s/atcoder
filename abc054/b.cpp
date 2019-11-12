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
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        cin >> b[i];
    }

    for (int y = 0; y <= n - m; y++) {
        for (int x = 0; x <= n - m; x++) {
            bool ok = true;
            rep(i, m) rep(j, m) {
                if (a[y + i][x + j] != b[i][j]) ok = false;
            }

            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}

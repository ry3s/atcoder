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
    int n; cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i], --p[i];

    int cnt = 0;
    rep(i, n) {
        if (p[i] == i) {
            if (p[i] == n - 1) swap(p[i - 1], p[i]);
            else swap(p[i], p[i + 1]);

            ++cnt;
        }
    }
    cout << cnt << endl;
}

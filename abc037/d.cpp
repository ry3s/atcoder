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

const long long MOD = 1e9 + 7;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<long long>> a(h, vector<long long>(w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }


}

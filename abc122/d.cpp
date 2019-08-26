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

const LL MOD = 1e9 + 7;
template<class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
// 0: dummy, 1: A, 2:G 3: C, 4: T
LL solve(int n) {
    auto dp = make_vec<LL>(n + 1, 5, 5, 5);
    dp[0][0][0][0] = 1;
    rep(x, n) rep(i, 5) rep(j, 5) rep(k, 5) loop(l, 1, 5) {
        if (i == 1 && j == 2 && l == 3) continue;
        if (i == 1 && k == 2 && l == 3) continue;
        if (j == 1 && k == 2 && l == 3) continue;
        if (j == 2 && k == 1 && l == 3) continue;
        if (j == 1 && k == 3 && l == 2) continue;

        dp[x + 1][j][k][l] = (dp[x + 1][j][k][l] + dp[x][i][j][k]) % MOD;
    }
    LL res = 0;
    loop(i, 1, 5) loop(j, 1, 5) loop(k, 1, 5) {
        res = (res + dp[n][i][j][k]) % MOD;
    }
    return res % MOD;
}
int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}

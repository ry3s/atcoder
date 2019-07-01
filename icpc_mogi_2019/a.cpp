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
void solve(int n, int m) {
    int hitori = m / n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int ans = 0;
    rep(i, n) {
        if (a[i] >= hitori) {
            ans += hitori;
        } else {
            ans += a[i];
        }
    }
    cout << ans << endl;
}
int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 and m == 0) break;

        solve(n, m);
    }
}

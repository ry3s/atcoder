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
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    vector<LL> b(n);
    rep(i, n + 1) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    LL ans = 0;
    rep(i, n) {
        LL rest = b[i] - a[i];
        if (rest <= 0) {
            ans += b[i];
            continue;
        } else {
            ans += a[i];
            if (a[i + 1] - rest >= 0) {
                ans += rest;
                a[i + 1] = a[i + 1] - rest;
            } else {
                ans += a[i + 1];
                a[i + 1]  = 0;
            }
        }
    }
    cout << ans << endl;
}

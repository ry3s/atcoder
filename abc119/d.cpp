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

const LL INF = 1e12;
template<class T> int former(const vector<T> &v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template<class T> int latter(const vector<T> &v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
int main() {
    int a, b, q; cin >> a >> b >> q;
    vector<LL> s(a), t(b);;
    rep(i, a)cin >> s[i];
    rep(i, b) cin >> t[i];
    s.push_back(INF); s.push_back(-INF); sort(s.begin(), s.end());
    t.push_back(INF); t.push_back(-INF); sort(t.begin(), t.end());

    rep(zzz, q) {
        LL x; cin >> x;
        LL res = INF;

        // s を先に
        rep(i, 2) {
            LL first = (i ? s[former(s, x)] : s[latter(s, x)]);

            rep(j, 2) {
                LL second = (j ? t[former(t, first)] : t[latter(t, first)]);
                res = min(res, abs(x - first) + abs(first - second));
            }
        }
        // t を先に
        rep(i, 2) {
            LL first = (i ? t[former(t, x)] : t[latter(t, x)]);

            rep(j, 2) {
                LL second = (j ? s[former(s, first)] : s[latter(s, first)]);
                res = min(res, abs(x - first) + abs(first - second));
            }
        }
        cout << res << endl;
    }

}

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

int main() {
    long long n, d, k; cin >> n >> d >> k;
    vector<pair<long long, long long>> v;
    rep(i, d) {
        long long l, r; cin >> l >> r;
        v[i] = { l, r };
    }
    vector<pair<long long, long long>> v2;
    rep(i, k) {
        long long s, t; cin >> s >> t;
        v2[i] = { s, t };
    }

    for (const auto& x: v2) {
        long long dest = x.second;
        long long cur = x.first;

        rep(day, d) {
            auto l = v[day].first;
            auto r = v[day].second;

            if (cur >= l && cur <= r) {
                if (dest >= l && dest <= r) {
                    cout << day + 1 << endl;
                }
            } else {

            }
        }
    }
}

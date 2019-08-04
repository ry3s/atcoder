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
#include <numeric>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;
vector<LL> divisor(LL sum) {
    vector<LL> ret;
    for (LL x = 1; x * x <= sum; x++) {
        if (sum % x == 0) {
            ret.push_back(x);
            if (x * x != sum) {
                ret.push_back(sum / x);
            }
        }
    }
    return ret;
}

int main() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    LL sum = accumulate(a.begin(), a.end(), 0);
    auto divs = divisor(sum);
    sort(divs.begin(), divs.end());
    LL ans = 1;
    for (auto d : divs) {
        LL tmp_ans= 101010101;
        vector<LL> tmp;
        LL rem = 0;
        for (auto j : a) {
            if (j % d <= (d - j % d)) {
                tmp.push_back(-j % d);
                rem += j % d;
            } else {
                tmp.push_back(d - j % d);
                rem += -d + j % d;

            }
        }
        sort(tmp.begin(), tmp.end());

        if (rem < 0) reverse(tmp.begin(), tmp.end());
        rem /= d;

        if (rem < 0) {
            rem *= -1;
            rep(i, rem) {
                tmp[i] -= d;
            }
        } else {
            rep(i, rem) {
                tmp[i] += d;
            }
        }
        LL pos = 0;
        LL neg = 0;
        for (auto i : tmp) {
            if (i >= 0) pos += i;
            else neg -= i;
        }
        tmp_ans = max(pos, neg);
        if (tmp_ans <= k) ans = d;
    }
    cout << ans << endl;
}

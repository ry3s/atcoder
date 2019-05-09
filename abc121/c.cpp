#include <cstdio>
#include <climits>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
struct mise {
    LL a;
    LL b;
};
bool cmp(const mise &x, const mise &y) {
    return x.a < y.a;
}
int main() {
    LL n, m;
    cin >> n >> m;

    vector<mise> v;
    rep(i, n) {
        LL x, y;
        mise tmp;
        cin >> x >> y;
        tmp.a = x;
        tmp.b = y;
        v.push_back(tmp);
        //cout << tmp.a << " " << tmp.b << endl;

    }
    sort(v.begin(), v.end(), cmp); // [](const mise &x, const mise &y) {
                             //     return x.a < y.a;
                             //     });
    LL res = 0;
    rep(i, n) {
        mise tmp = v[i];
        LL a = tmp.a;
        LL b = tmp.b;

        if (m - b <= 0) {
            res += a * m;
            break;
        } else {
            m -= b;
            res += a * b;
        }

    }
    cout << res << endl;

    return 0;
}

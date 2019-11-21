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

long long fact(long long n) {
    long long ret = 1;
    loop(i, 1, n + 1) {
        ret *= i;
    }
    return ret;
}
int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);

    rep(i, n) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }

    sort(v.begin(), v.end());
    double sum = 0.;
    int cnt = 0;
    do {
        auto prev = v[0];

        loop(i, 1, n) {
            auto cur = v[i];
            double dist = (prev.first - cur.first) *  (prev.first - cur.first)
                + (prev.second - cur.second) * (prev.second - cur.second);
            dist = sqrt(dist);

            sum += dist;
            prev = cur;
            cnt++;
        }
    } while(next_permutation(v.begin(), v.end()));

    double ans = sum / (double)fact(n);
    printf("%.8lf\n", ans);
}

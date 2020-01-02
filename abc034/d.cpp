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

bool check(double p, int n, int k,
           const vector<pair<double, double>> v) {
    vector<double> diff;
    rep(i, n) {
        diff.push_back((v[i].second * 0.01 - p * 0.01) * v[i].first);
    }
    sort(diff.begin(), diff.end(), greater<>());

    double sum = 0;
    rep(i, k) {
        sum += diff[i];
    }
    return sum <= 0;
}
int main() {
    int n, k; cin >> n >> k;
    vector<pair<double, double>> v(n);
    rep(i, n) {
        double w, p; cin >> w >> p;
        v[i] = { w, p };
    }

    // binary search
    double ok = 100.0, ng = -1.0;
    rep(i, 100) {
        double mid = (ok + ng) / 2.0;

        if (check(mid, n, k, v)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    printf("%.10lf\n", ok);
}

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
const double eps = 1e-11;
int64_t com[64][64];
int main() {
    com[0][0] = 1;
    for (int i = 1; i < 64; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i - 1][j];
            if (j > 0) com[i][j] += com[i - 1][j - 1];
        }
    }

    int n, a, b; cin >> n >> a >> b;
    vector<uint64_t> values(n);
    for (auto &v: values) cin >> v;

    sort(values.begin(), values.end(), greater<>());

    uint64_t sum = 0;
    rep(i, a) {
        sum += values[i];
    }
    double avg = sum / (double) a;

    int64_t res = 0;
    int cnt = 0;
    for (auto &v: values) {
        if (v == values[a - 1]) ++cnt;
    }

    if (values[0] == values[a - 1]) {
        for (int j = a; j <= b; j++) {
            res += com[cnt][j];
        }
    } else {
        int x = 0;
        rep(i, a) if (values[i] == values[a - 1]) ++x;
        res += com[cnt][x];
    }
    printf("%.7f\n", avg);
    cout << res << endl;
}

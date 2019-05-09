#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(val) cout << "!!!" << #val << ": " << val << endl
#define mod 1000000007
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int D;
    LL G;
    cin >> D >> G;

    vector<LL> p(D), c(D);

    rep(i, D) {
        cin >> p[i] >> c[i];
    }

    LL res = 1 << 29;
    rep(bit, 1<<D) {
        LL sum = 0;
        LL num = 0;
        // 全完する問題の得点を合計
        rep(i, D) {
            if (bit & (1 << i)) {
                sum += c[i] + p[i] * 100 * (i + 1);
                num += p[i];
            }
        }
        if (sum >= G) {
            res = min(res, num);
        } else {
            for (int i = D - 1; i >= 0; i--) {
                if (bit & (1 << i)) continue;

                rep(j, p[i]) {
                    if (sum >= G) break;
                    sum += 100 * (i + 1);
                    num++;
                }
            }
            res = min(res, num);
        }
    }

    cout << res << endl;
    return 0;

}

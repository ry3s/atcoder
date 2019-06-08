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

int main() {
    int n, k;
    cin >> n >> k;
    vector<LL> values;
    rep(i, n) {
        LL value;
        cin >> value;
        values.push_back(value);
    }
    LL n_iter = min(n, k);
    LL ans = 0;
    rep(left, n_iter + 1) {
        rep(right, n_iter + 1) {
            if (left + right > n_iter) continue;

            vector<LL> having;
            rep(i, left) {
                having.push_back(values[i]);
            }
            rep(i, right) {
                having.push_back(values[n - i - 1]);
            }
            sort(having.begin(), having.end());

            LL num_waste = k - left - right;
            LL res = 0;
            rep(i, having.size()) {
                if (num_waste > 0 and having[i] < 0) {
                    num_waste--;
                    continue;
                }

                res += having[i];
            }
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}

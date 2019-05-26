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
struct ans{
    int num_throw;
    int num_pop;
    LL value;
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<LL> values;
    rep(i, n) {
        LL value;
        cin >> value;
        values.push_back(value);
    }
    vector<LL> acc_left(n + 1), acc_right(n + 1);
    acc_left[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        acc_left[i] = acc_left[i - 1] + values[i];
    }
    acc_right[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        acc_right[i] = acc_right[i + 1] + values[i];
    }

    rep(i, n) {
        rep(j, n) {
            LL res = acc_left[i] + acc_right[j];
            LL num_throw = k - i - j;
            if (num_throw < 0) continue;


        }
    }
    cout << res << endl;
    return 0;
}

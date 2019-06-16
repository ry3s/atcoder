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
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<LL> v(n + 1);
    v[0] = 0;
    for (LL i = 1; i < n + 1; i++) {
        v[i] = v[i - 1] + a[i - 1];
    }
    LL cnt = 0;
    LL right = 0;
    LL sum = 0;
    for (LL i = 0; i < n; i++) {
        while (right < n and sum + a[right] < k) {
            sum += a[right];
            right++;
        }
        cnt += n - right;

        if (i == right) right++;
        else sum -= a[i];
    }
    cout << cnt << endl;
    return 0;
}

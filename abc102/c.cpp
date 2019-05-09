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
#define mod 1000000007
using namespace std;
typedef long long int LL;

int main() {
    int N;
    cin >> N;

    vector<LL> a(N);
    rep(i, N) {
        cin >> a[i];
    }

    rep(i, N) {
        a[i] -= (i + 1);
    }

    sort(a.begin(), a.end());

    LL b = a[N / 2];

    LL ans = 0;
    rep(i, N) {
        ans += abs(a[i] - b);
    }

    cout << ans << endl;
    return 0;
}

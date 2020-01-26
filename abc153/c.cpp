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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<long long> arr(n);
    rep(i, n) cin >> arr[i];

    if (n <= k) {
        cout << 0<< endl;
        return 0;
    }

    sort(arr.begin(), arr.end(), greater<>());

    long long ans = 0;
    for (int i = k; i < n; i++) {
        ans += arr[i];
    }
    cout << ans << endl;
}

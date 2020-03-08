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
    int n, p; cin >> n >> p;
    string s; cin >> s;

    if (p == 2 || p == 5) {
        int64_t res = 0;
        rep(i, n) {
            if ((s[n - i - 1] - '0') % p == 0) {
                res += n - i;
            }
        }
        cout << res << endl;
        return 0;
    }

    vector<int64_t> arr(p, 0);
    int64_t position = 1;
    int64_t cur = 0;
    arr[cur]++;
    rep(i, n) {
        cur = (cur + (s[n - i - 1] - '0') * position) % p;
        position = (position * 10) % p;
        arr[cur]++;
    }
    int64_t res = 0;
    rep(i, p) {
        res += arr[i] * (arr[i] - 1) / 2;
    }
    cout << res << endl;
}

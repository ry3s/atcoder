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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
int max_against_votes(int n, const vector<int> &v, int x) {
    int ret = 0;
    rep(i, n) {
        if (i == x) continue;

        ret = max(ret ,v[i]);
    }
    return ret;
}
void solve(int n) {
    vector<char> c(n);
    rep(i, n) {
        cin >> c[i];
    }
    vector<int> candidates(26, 0);

    rep(i, n) {
        candidates[c[i] - 'A']++;

        // check
        rep(x, 26) {
            if (max_against_votes(26, candidates, x) + n - (i + 1) < candidates[x]) {
                printf("%c %d\n", x + 'A', i + 1);
                return;
            }
        }

    }
    cout << "TIE" << endl;
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
    return 0;
}

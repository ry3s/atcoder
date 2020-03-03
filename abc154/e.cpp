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

int64_t com(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    if (r == 1) return n;
    else if (r == 2) return n * (n - 1) / 2;
    else return n * (n - 1) * (n - 2) / 6;
}

int64_t pow(int64_t n, int64_t k) {
    int64_t res = 1;
    rep(i, k) res *= n;
    return res;
}
string s;
int n, k;

int64_t rec(int i, int k, bool smaller) {
    if (i == n) {
        if (k == 0) return 1;
        else return 0;
    }
    if (k == 0) return 1;

    if (smaller) return com(n - i, k) * pow(9, k);
    else {
        if (s[i] == '0') return rec(i + 1, k, false);
        else {
            return rec(i + 1, k, true)
                + rec(i + 1, k - 1, true) * (s[i] - '1')
                + rec(i + 1, k - 1, false);
        }
    }
}
int main() {
    cin >> s;
    cin >> k;
    n = s.size();

    cout << rec(0, k, false) << endl;
}

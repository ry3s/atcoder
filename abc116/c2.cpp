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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    long long n, h[100], k[100] = {0};
    long long i, l, r, ans = 0;

    cin >> n;
    rep(i, n) {
        cin >> h[i];
    }

    while (true) {
        for (l = 0; l < n; l++) {
            if (k[l] < h[l]) break;
        }

        for(r = l; r < n; r++) {
            if (k[r] == h[r]) break;
        }

        if (l == n and r == n) break;

        for (i = l; i < r; i++) k[i]++;

        ans++;
    }

    cout << ans << endl;

    return 0;
}

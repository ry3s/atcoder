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

void solve(int n) {
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int diff_min = 1e9;
    rep(i, n - 1) {
        for (int j = i + 1; j < n; j++) {
            if (abs(a[i] - a[j]) < diff_min) {
                diff_min = abs(a[i] - a[j]);
            }
        }
    }
    cout << diff_min << endl;
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        solve(n);
    }

}

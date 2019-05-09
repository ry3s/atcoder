#include <cstdio>
#include <climits>
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
#include <numeric>
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    LL n;
    cin >> n;
    vector<LL> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    LL cnt = 0;
    LL min = 2143234423141231422;
    rep(i, n) {
        if (a[i] < 0) {
            cnt++;
        }
        min = min > abs(a[i]) ? abs(a[i]) : min;
    }

    LL res = 0;
    rep(i, n) {
        res += abs(a[i]);
    }
    cout << (cnt % 2 == 0 ? res : res - 2 * min) << endl;

}

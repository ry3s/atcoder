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
#include <bitset>
#include <iterator>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int a, b, t;
    cin >> a >> b >> t;

    LL res = 0;
    int cnt = 1;
    rep(i, t + 1) {
        if (i == a * cnt) {
            res += b;
            // cout << "!" << endl;
            cnt++;
        }
    }
    cout << res <<endl;
    return 0;
}

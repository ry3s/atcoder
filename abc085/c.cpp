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
    int n;
    LL y;
    cin >> n >> y;

    rep(a, n + 1) {
        rep(b, n + 1) {
            LL c = n - a - b;
            if (c >= 0
                and 10000LL * a + 5000LL * b + 1000L * c == y) {
                printf("%d %d %d\n", a, b, c);
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;

    return 0;
}

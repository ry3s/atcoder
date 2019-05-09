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
    LL n, y;
    cin >> n >> y;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            for (int k = 0; k <= n - i - j; k++) {
                if (y == 10000 * i + 5000 * j + 1000 *k
                    and i + j + k == n) {
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}

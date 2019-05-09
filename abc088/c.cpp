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
    int grid[3][3];
    int a[3] = {0}, b[3];
    rep(i, 3) {
        rep(j, 3) {
            cin >> grid[i][j];
        }
    }

    rep(i, 3) {
        b[i] = grid[0][i];
    }
    rep(i, 3) {
        a[i] = grid[i][0] - b[0];
    }

    rep(i, 3) {
        rep(j, 3) {
            if (grid[i][j] != a[i] + b[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}

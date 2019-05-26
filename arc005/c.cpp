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

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char> > c(h, vector<char>(w));
    int sy, sx, gy, gx;
    rep(i, h) {
        rep(j, w) {
            char ch;
            cin >> ch;
            c[i][j] = ch;
            if (ch == 's') {
                sy = i;
                sx = j;
            } else if (ch == 'g') {
                gy = i;
                gx = j;
            }

        }
    }
    return 0;
}

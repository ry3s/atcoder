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

int main() {
    long long h, w; cin >> h >> w;

    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (h % 2 == 0) {
        long long tate = h / 2;
        cout << tate * w << endl;
    } else {
        long long tate1 = h / 2 + 1;
        long long tate2 = tate1 - 1;

        if (w % 2 == 0) {
            cout << tate1 * (w / 2) + tate2 * (w / 2) << endl;
        } else {
            long long yoko1 = w / 2 + 1;
            long long yoko2 = yoko1 - 1;
            cout << tate1 * yoko1 + tate2 * yoko2 << endl;
        }
    }
}

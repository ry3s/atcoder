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
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;
LL f(LL height, LL width) {
    LL ret = (1LL << 60);

    int a = 0, b = 0, c = 0;
    for (LL h = 0; h <= height; ++h) {
        if (width % 2 == 0) a = h * width / 2, b = h * width / 2;
        else a = h * (width - 1) / 2, b = h * (width + 1) / 2;
        c = (height - h) * width;

        LL maxi = max({a, b, c});
        LL mini = min({a, b, c});
        cout << maxi - mini << endl;
        ret = min(ret, maxi - mini);

        a = h * width;
        if ((height - h) % 2 == 0) b = (height - h) / 2 * width, c = b;
        else b = (height - h - 1) / 2 * width, c = (height - h + 1) / 2 * width;

        maxi = max({a, b, c});
        mini = min({a, b, c});
        cout << maxi - mini << endl;
        ret = min(ret, maxi - mini);
    }
    return ret;
}
int main() {
    int h, w; cin >> h >> w;
    cout << min(f(h, w), f(w, h)) << endl;
}

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
    uint64_t h; cin >> h;

    long long ans = 1;
    while (h > 0) {
        h = h/ 2;
        ans *= 2;
    }
    cout << (ans - 1)<< endl;
}

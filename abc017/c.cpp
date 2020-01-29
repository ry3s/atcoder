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
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> arr(n);
    rep(i, n) {
        int l, r, s; cin >> l >> r >> s;
        arr[i] = { l, r, s };
    }

}

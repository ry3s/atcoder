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
    string s; cin >> s;
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    rep(i, n) {
        int l, r; cin >> l >> r;
        arr[i] = { l - 1, r };
    }
    for (auto p: arr) {
        int l = p.first;
        int r = p.second;
        reverse(s.begin() + l , s.begin() + r);
    }
    cout << s << endl;
}

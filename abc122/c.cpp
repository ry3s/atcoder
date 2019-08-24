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
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<int, int>> v;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        v.push_back(make_pair(l, r));
    }
    vector<LL> left(n + 1);
    left[0] = 0;
    bool pre = false;
    rep(i, n) {
        if (s[i] == 'A') {
            pre = true;
            left[i + 1] = left[i];
        }
        else if (s[i] == 'C' and pre) {
            left[i + 1] = left[i] + 1;
            pre = false;
        } else {
            left[i + 1] = left[i];
            pre = false;
        }
    }
    // vector<LL> right(n + 1);
    // right[n] = 0;
    // pre = false;
    // for (int i = n - 1; i >= 0; i--) {
    //     if (s[i] == 'C') {
    //         pre = true;
    //         right[i] = right[i + 1];
    //     } else if (s[i] == 'A' and pre) {
    //         right[i] = right[i + 1] + 1;
    //         pre = false;
    //     } else {
    //         right[i] = right[i + 1];
    //         pre = false;
    //     }
    // }
    for (auto &lr : v) {
        int l = lr.first;
        int r = lr.second;
        cout << left[r] - left[l] << endl;
    }
}

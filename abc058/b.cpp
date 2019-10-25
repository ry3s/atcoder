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

int main() {
    string o, e; cin >> o >> e;

    vector<char> ans;
    rep(i, o.size()) {
        ans.push_back(o[i]);
        if (i == (int)e.size()) continue;
        ans.push_back(e[i]);
    }
    for (auto &ch: ans) {
        cout << ch;
    }
    cout << endl;
}

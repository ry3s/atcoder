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
vector<string> ans;

void solve(int i, int n, string acc, set<char> x) {
    if (i == n) {
        ans.push_back(acc);
        return;
    }

    rep(j, x.size() + 1) {
        auto tmp = x;
        tmp.insert((char)('a' + j));
        solve(i + 1, n, acc + (char)('a' + j), tmp);
    }

    // if (prev == 'a') {
    //     solve(i + 1, n, acc + 'a');

    // } else {
    //     solve(i + 1, n, acc + 'a');
    //     solve(i + 1, n, acc + prev);
    //     solve(i + 1, n, acc + (char)(prev + 1));
    // }
}

int main() {
    int n; cin >> n;

    solve(1, n, "a", {'a'});
    for (auto x: ans) {
        cout << x << endl;
    }
}

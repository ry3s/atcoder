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

void dfs(int i, int n, string s) {
    if (i == n) {
        ans.push_back(s);
        return;
    }

    rep(j, 3) {
        string tmp = s;
        if (j == 0) tmp += 'a';
        else if (j == 1) tmp += 'b';
        else tmp += 'c';

        dfs(i + 1, n, tmp);
    }

}
int main() {
    int n; cin >> n;

    dfs(0, n, "");

    for (auto ch: ans) {
        cout << ch << endl;
    }
}

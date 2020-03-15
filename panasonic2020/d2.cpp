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

void dfs(string s, char mx, int n) {
    if ((int)s.length() == n) {
        cout << s << endl;
    } else {
        for (char c = 'a'; c <= mx; c++) {
            dfs(s + c,
                ((c == mx) ? (char)(mx + 1) : mx),
                n);
        }
    }
}

int main() {
    int n; cin >> n;
    dfs("", 'a', n);

}

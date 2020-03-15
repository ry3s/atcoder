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
    int t; cin >> t;
    int n; cin >> n;
    queue<int> q;
    for (int i = 0; i <  n; i++) {
        int a; cin >> a;
        q.push(a);
    }

    int m; cin >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x <= b && b <= x + t) {
                ans++;
                break;
            }
        }
    }
    if (ans == m) cout << "yes" << endl;
    else cout << "no" << endl;
}

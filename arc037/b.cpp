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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > edge(n, vector<int>(n, 0));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        edge[x - 1][y - 1] = 1;
    }
    vector<bool> visited_node(n, false);
    int ans = 0;
    rep(i, n) {
        if (visited_node[i] == true) continue;
        // DFS
        stack<int> stck;
        stck.push(i);
        visited_node[i] = true;
        bool is_looped = false;
        while (not stck.empty()) {
            int current = stck.top();
            stck.pop();

            rep(j, n) {
                if (edge[current][j] == 1
                    and visited_node[j] == true) {
                    is_looped = true;
                }
                if (edge[current][j] == 1
                    and visited_node[j] == false) {
                    stck.push(j);
                    visited_node[j] = true;
                }
            }
        }
        if (not is_looped) ans++;

    }
    cout << ans << endl;
    return 0;
}

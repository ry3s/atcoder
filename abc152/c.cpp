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
    int n; cin >> n;
    vector<int> arr(n);
    rep(i, n) cin >> arr[i];
    priority_queue<int, vector<int>, greater<int>> Q;

    int cnt = 0;
    for (auto p: arr) {
        Q.push(p);
        if (p <= Q.top()) {
            cnt++;
        }
        Q.push(p);
    }
    cout << cnt << endl;
}

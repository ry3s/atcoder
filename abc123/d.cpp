#include <cstdio>
#include <climits>
#include <cassert>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
using Data = pair<LL, vector<LL>>;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<LL> a(X), b(Y), c(Z);
    rep(i, X) {
        cin >> a[i];
    }
    rep(i, Y) {
        cin >> b[i];
    }
    rep(i, Z) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<LL>());
    sort(b.begin(), b.end(), greater<LL>());
    sort(c.begin(), c.end(), greater<LL>());
    priority_queue<Data> que;
    set<Data> se;
    que.push(Data(a[0] + b[0] + c[0], vector<LL>({0, 0, 0})));
    rep(k, K) {
        auto cur = que.top();
        que.pop();
        cout << cur.first << endl;

        if (cur.second[0] + 1 < X) {
            LL sum = cur.first - a[cur.second[0]] + a[cur.second[0] + 1];
            auto num = cur.second;
            num[0]++;
            auto d = Data(sum, num);
            if (not se.count(d)) {
                se.insert(d);
                que.push(d);
            }
        }
        if (cur.second[1] + 1 < Y) {
            LL sum = cur.first - b[cur.second[1]] + b[cur.second[1] + 1];
            auto num = cur.second;
            num[1]++;
            auto d = Data(sum, num);
            if (not se.count(d)) {
                se.insert(d);
                que.push(d);
            }
        }
        if (cur.second[2] + 1 < Z) {
            LL sum = cur.first - c[cur.second[2]] + c[cur.second[2] + 1];
            auto num = cur.second;
            num[2]++;
            auto d = Data(sum, num);
            if (not se.count(d)) {
                se.insert(d);
                que.push(d);
            }
        }

    }
    return 0;
}

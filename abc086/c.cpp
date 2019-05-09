#include <cstdio>
#include <climits>
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
#define mod 1000000007
using namespace std;
typedef long long int LL;

int manhattan_dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > v;
    vector<int> time;
    rep(i, n) {
        int t;
        int x, y;
        cin >> t >> x >> y;
        v.push_back(make_pair(x, y));
        time.push_back(t);
    }
    if ((manhattan_dist(v[0], make_pair(0, 0)) != time[0]
         and (manhattan_dist(v[0], make_pair(0, 0)) ) % 2 == 0)
        or manhattan_dist(v[0], make_pair(0, 0)) > time[0]) {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 1; i < n; i++) {
        int dist = manhattan_dist(v[i], v[i - 1]);
        // cout << "!!!" << dist << endl;
        int t = time[i] - time[i - 1];
        if ((dist != t and dist % 2 == 0) or dist > t) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

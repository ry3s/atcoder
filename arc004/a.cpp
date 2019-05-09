#include <cstdio>
#include <climits>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > vp;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        vp.push_back(make_pair(x, y));
    }
    double max_distance = 0.0;

    for (int i = 0; i < n - 1; i++) {
        int x1 = vp[i].first;
        int y1 = vp[i].second;
        for (int j = i + 1; j < n; j++) {
            int x2 = vp[j].first;
            int y2 = vp[j].second;

            double dist = pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
            max_distance = dist > max_distance ? dist : max_distance;
        }
    }

    cout << sqrt(max_distance) << endl;
    return 0;

}

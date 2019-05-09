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
#define dump(variable) cout << #variable << ": " << variable << endl
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {

    int n;
    cin >> n;
    vector<vector<int> > v(2, vector<int>(100005));
    vector<int> mode(2);
    vector<int> maxi(2);
    rep(i, n / 2) {
        int x, y;
        cin >> x >> y;
        v[0][x]++;
        v[1][y]++;

        if (mode[0] < v[0][x]) {
            mode[0] = v[0][x];
            maxi[0] = x;
        }
        if (mode[1] < v[1][y]) {
            mode[1] = v[1][y];
            maxi[1] = y;
        }
    }
    sort(v[0].begin(), v[0].end(), greater<int>());
    sort(v[1].begin(), v[1].end(), greater<int>());

    int ans = 0;
    if (maxi[0] != maxi[1]) {
        ans = n - mode[0] - mode[1];
    } else {
        ans = min(n - mode[0] - v[1][1], n - mode[1] - v[0][1]);
    }
    cout << ans << endl;
    return 0;
}

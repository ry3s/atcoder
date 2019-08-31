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
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long;
using ULL = unsigned long long;

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, LL>> sushi(n); // (t, d)
    rep(i, n) {
        int t; LL d;
        cin >> t >> d;
        sushi[i] = make_pair(t - 1, d);
    }

    sort(sushi.begin(), sushi.end(), [](const auto &a, const auto &b) {
                                         return a.second > b.second;
                                     });

    map<int, LL> kinds;
    LL sum = 0;
    rep(i, k) {
        auto td = sushi[i];
        sum += td.second;
        kinds[td.first]++;
    }
    LL ans = sum + kinds.size() * kinds.size();
    int index = k - 1;
    for (int i = k; i < n; i++) {
        auto td = sushi[i];
        if (kinds[td.first] != 0){
            continue;
        } else {
            kinds[td.first]++;

            while (index >= 0  and kinds[sushi[index].first] == 1) {
                index--;
            }

            if (index == -1) break;
            sum += td.second - sushi[index].second;
            kinds[sushi[index].first]--;
            index--;
            ans = max(ans, sum + (LL)kinds.size() * (LL)kinds.size());
        }
    }
    cout << ans << endl;
}

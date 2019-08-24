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
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    vector<int> v(5);
    rep(i, 5) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 1e8;
    do {
        int cur_time = 0;
        rep(i, 5) {
            cur_time += v[i];
            if (i == 4) break;

            if (cur_time % 10 == 0) continue;
            else {
                cur_time += 10 - (cur_time % 10);
            }
        }
        ans = min(ans, cur_time);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

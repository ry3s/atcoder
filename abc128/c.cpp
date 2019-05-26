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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int x;
            cin >> x;
            v[i].push_back(x - 1);
        }
    }
    vector<int> p(m);
    rep(i, m) {
        cin >> p[i];
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool off_flag = false;
        rep(i, m) {
            int num_on = 0;
            for (int j: v[i]) {
                if (bit & (1 << j)) {
                    num_on++;
                }
            }
            //debug(num_on);
            if ((num_on % 2) == p[i]) {
                continue;
            } else {
                off_flag = true;
            }
        }

        if (off_flag == false){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

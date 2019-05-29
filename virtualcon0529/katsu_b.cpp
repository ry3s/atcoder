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
    int n;
    cin >> n;
    vector<pair<LL, LL> > v;
    rep(i, n) {
        LL a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    auto ans = v[0];
    LL index = 1;
    for (LL i = 1; i < n; i++) {
        auto ab = v[i];
        LL a = ab.first;
        LL b = ab.second;
        LL ansa = ans.first;
        LL ansb = ans.second;

        LL hp_ans = ansa / b;
        LL rest_ans = ansa % b;
        LL hp_ab = b / ansb;
        LL rest_ab = b % ansb;
        debug(ansa/b);
        debug(a/ ansb);

        if ((hp_ans == 0 or (hp_ans == 1 and rest_ans == 0))
            and hp_ab == 0) {
            index = -1;
        } else if (hp_ans  hp_ab)
    }
    cout << index << endl;
}

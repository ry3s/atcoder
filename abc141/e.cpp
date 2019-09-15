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

vector<int> common_prefix(string str) {
    int n = str.size();

    vector<int> ret(n, 0);
    ret[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n and str[j] == str[i + j]) ++j;

        ret[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < n and k + ret[k] < j) ret[i + k] = ret[k], ++k;
        i += k; j -= k;
    }
    return ret;
}
int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    rep(i, n) {
        auto prefix = common_prefix(s.substr(i, n - i));
        rep(j, prefix.size()) prefix[j] = min(prefix[j], (int)j);

        ans = max(ans, *max_element(prefix.begin(), prefix.end()));
    }
    cout << ans << endl;
    return 0;
}

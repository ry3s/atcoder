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
    vector<string> vs(n);
    rep(i, n) {
        cin >> vs[i];
    }

    LL cnt = 0, cntba = 0, cntb = 0, cnta = 0;
    rep(i, n) {
        int len = vs[i].length();
        for (int j = 0; j < len - 1; j++) {
            if (vs[i][j] == 'A' and vs[i][j + 1] == 'B') cnt++;
        }


        char s_first = vs[i][0];
        char s_last = vs[i][len - 1];
        if (s_first == 'B' and s_last == 'A') {
            cntba++;
        } else if (s_first == 'B') {
            cntb++;
        } else if (s_last == 'A') {
            cnta++;
        }
    }
    LL ans = 0;
    if (cntba == 0) {
        ans = cnt + min(cnta, cntb);
    } else {
        if (cnta + cntb > 0) {
            ans = cnt + cntba + min(cnta, cntb);
        } else {
            ans = cnt + cntba - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <map>
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
    string s; cin >> s;

    int ans = 0;
    for (int i = s.size() - 1; i != 0; --i) {
        if (i % 2 != 0) continue;

        bool ok = true;
        rep(j, i / 2) {
            if (s[j] != s[j + i / 2]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

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
    string s;
    cin >> s;
    int n = s.size();
    int max_length = 0;
    rep(i, n) {
        loop(j, 1, n + 1) {
            string sub = s.substr(i, j);
            bool ok = true;
            for (auto x : sub) {
                if (x != 'A' and x != 'C' and x != 'G' and x != 'T') {
                    ok = false;
                }
            }
            if (ok) {
                max_length = max(max_length, (int)sub.size());
            }
        }
    }
    cout << max_length << endl;
    return 0;
}

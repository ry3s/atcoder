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
    string sa, sb, sc; cin >> sa >> sb >> sc;

    int ia = 0, ib = 0, ic = 0;
    char cur = 'a';
    while (true) {
        if (cur == 'a') {
            if (ia == sa.size()) {
                cout << "A" << endl;
                return 0;
            }
            cur = sa[ia];
            ia++;
        } else if (cur == 'b') {
            if (ib == sb.size()) {
                cout << "B" << endl;
                return 0;
            }
            cur = sb[ib];
            ib++;
        } else {
            if (ic == sc.size()) {
                cout << "C" << endl;
                return 0;
            }
            cur = sc[ic];
            ic++;
        }
    }

}

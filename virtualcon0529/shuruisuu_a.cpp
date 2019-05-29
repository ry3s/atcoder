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
    set<pair<LL, LL> > st;
    rep(i, n) {
        LL a, b;
        cin >> a >> b;
        if (a < b) {
            st.insert(make_pair(a, b));
        } else {
            st.insert(make_pair(b, a));
        }
    }

    cout << st.size() << endl;
}

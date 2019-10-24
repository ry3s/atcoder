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
    int n; cin >> n;
    set<int> st;
    int over = 0;
    rep(i, n) {
        int a; cin >> a;
        if (a >= 3200) ++over;
        else st.insert(a/400);
    }

    int maxi = (int)st.size() + over;
    int mini = 0;
    if (st.size() == 0) mini = 1;
    else mini = (int) st.size();

    cout << mini << " " << maxi << endl;
}

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
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;

int main() {
    long long n, k; cin >> n >> k;

    set<long long> st;
    long long x = abs(n - k);
    st.insert(abs(n - k));
    long long mini = abs(n - k);
    if (n % k == 0) {
        cout << 0 << endl;
        return 0;
    } else if (n < k) {
        cout << min(n, abs(n - k)) << endl;
        return 0;
    }
    while (true) {
        x = abs(x - k);
        if (st.find(x) != st.end()) {
            cout << mini << endl;
            return 0;
        } else {
            st.insert(x);
            mini = min(mini, x);
        }
    }

}

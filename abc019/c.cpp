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
    int n; cin >> n;
    vector<long long> arr(n);
    rep(i, n) cin >> arr[i];

    set<long long> st;
    for (auto a: arr) {
        while (a % 2 == 0) {
            a /= 2;
        }
        st.insert(a);
    }
    cout << st.size() << endl;
}

#include <cstdio>
#include <climits>
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
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    LL sum = 0;
    for (int i = 1; i < n; i++) {
        sum += v[i];
    }
    if (sum > v[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

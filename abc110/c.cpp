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
#define dump(variable) cout << #variable << ": " << variable << endl
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> c1(26), c2(26);

    rep(i, s.size()) {
        c1[s[i] - 'a']++;
        c2[t[i] - 'a']++;
    }

    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());

    if (c1 == c2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;

}

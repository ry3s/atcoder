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
    int k, x;
    cin >> k >> x;
    vector<int> ans;
    for (int i = x - k + 1; i <= x + k - 1; i++) {
        if (i >= -1000000 and i <= 1000000) {
            ans.push_back(i);
        }
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

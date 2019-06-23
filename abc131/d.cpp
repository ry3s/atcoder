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
    LL n;
    cin >> n;
    vector<pair<LL, LL>> v(n);
    rep(i, n) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](auto a, auto b){
                                 return a.second < b.second;
                             });
    LL sum = 0;
    rep(i, n) {
        sum += v[i].first;
        if (sum > v[i].second) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

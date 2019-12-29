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
int dp[101010][3];

int main() {
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;
    string t; cin >> t;


    map<char, int> value = { { 'r' , r }, { 's' , s }, { 'p' , p }};
    map<char, char> mp = { { 'r', 'p' }, { 's', 'r' }, { 'p', 's' }};

    long long sum = 0;
    rep(i, k) {
        char prev = mp[t[i]];
        sum += value[mp[t[i]]];
        for (int j = i + k; j < n; j += k) {
            char kachite = mp[t[j]];
            if (prev != kachite) {
                sum += value[kachite];
                prev = kachite;
            } else {
                prev = 'A';
            }

        }
    }
    cout << sum << endl;
}

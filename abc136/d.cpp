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
    string s;
    cin >> s;
    LL n = s.length();
    vector<LL> left(n, 0);
    vector<LL> right(n, 0);
    bool flag = true;
    int cur = 0;
    int pre = 0;
    rep(i, n) {
        if (s[i] == 'R') {
            if (flag == true) {
                cur++;
                flag = false;
            } else {
                pre++;
                flag = true;
            }
        } else {
            if (flag == true) {
                left[i] += cur;
                left[i - 1] += pre;
            } else {
                left[i] += pre;
                left[i - 1] += cur;
            }
            flag = true;
            cur = 0;
            pre = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            if (flag == true) {
                cur++;
                flag = false;
            } else {
                pre++;
                flag = true;
            }
        } else {
            if (flag == true) {
                right[i] += cur;
                right[i + 1] += pre;
            } else {
                right[i] += pre;
                right[i + 1] += cur;
            }
            flag = true;
            cur = 0;
            pre = 0;
        }
    }
    // for (auto x : left) {
    //     cout << x << " ";
    // }
    // cout << endl;
    //     for (auto x : right) {
    //     cout << x << " ";
    // }
    // cout << endl;
    rep(i, n) {
        if (i == n - 1) {
            cout << left[i] + right[i] << endl;
        } else {
            cout << left[i] + right[i]  << ' ';
        }
    }
    return 0;
}

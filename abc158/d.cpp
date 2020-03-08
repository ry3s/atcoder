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
    string s; cin >> s;
    int q; cin >> q;
    bool flag = true;
    deque<char> lst;
    for (auto ch: s) {
        lst.push_back(ch);
    }
    rep(i, q) {
        int t; cin >> t;
        if (t == 1) {
            flag = (flag ? false : true);
        } else {
            int f; char c; cin >> f >> c;
            if (f == 1 && flag) {
                lst.push_front(c);
            } else if (f == 1 && !flag) {
                lst.push_back(c);
            } else if (f == 2 && flag) {
                lst.push_back(c);
            } else {
                lst.push_front(c);
            }
        }
    }
    if (flag) {
        for (auto ch: lst) {
            cout << ch;
        }
    } else {
        for (auto it = lst.rbegin(); it != lst.rend(); it++) {
            cout << *it;
        }
    }

    cout << endl;
}

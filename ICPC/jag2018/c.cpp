#include <cstdio>
#include <climits>
#include <cassert>
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

using State = string::iterator;

string s, p;
int letter(State &begin);
int op(State &begin);
int exp(State &begin);
int myhash(State &begin);

int letter(State &begin) {
    switch (*begin) {
    case 'a':
        begin++;
        return p[0] - '0';
    case 'b':
        begin++;
        return  p[1] - '0';
    case 'c':
        begin++;
        return p[2] - '0';
    case 'd':
        begin++;
        return p[3] - '0';
    }
}
int exp(State &begin) {
//    if (*begin == '[') {
    begin++;
    if (*begin == '+') {
        begin++;
        int x = myhash(begin);
        int y = myhash(begin);
        begin++;
        return x | y;
    } else if (*begin == '*') {
        begin++;
        int x = myhash(begin);
        int y = myhash(begin);
        begin++;
        return x & y;
    } else if (*begin == '^') {
        begin++;
        int x = myhash(begin);
        int y = myhash(begin);
        begin++;
        return x ^ y;
        }
//    }
}
int myhash(State &begin) {
    if (*begin == '[') {
        return exp(begin);
    } else {
        return letter(begin);
    }

}
void solve() {
    cin >> p;
    State begin = s.begin();
    int ans =  myhash(begin);
    int num = 0;
    for (int i1 = 0; i1 <= 9; i1++) {
        for (int i2= 0; i2 <= 9; i2++) {
            for (int i3 = 0; i3 <= 9; i3++) {
                for (int i4 = 0; i4 <= 9; i4++) {
                    p[0] = i1 + '0';
                    p[1] = i2 + '0';
                    p[2] = i3 + '0';
                    p[3] = i4 + '0';
                    State b = s.begin();
                    if (myhash(b) == ans) {
                        num++;
                    }
                }
            }
        }
    }
    cout << ans << " " << num << endl;

}
int main() {
    while (true) {
        cin >> s;
        if (s == ".") break;
        solve();
    }
    return 0;
}

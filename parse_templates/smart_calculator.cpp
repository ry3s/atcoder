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
#include <cctype>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;

typedef string::const_iterator State;
class ParseError {};

int number(State &begin);
int factor(State &begin);
int term(State &begin);
int expression(State &begin);

int number (State &begin) {
    int ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}
int factor(State &begin) {
    int ret = 0;
    if (*begin == '(') {
        begin++; // '('を読み飛ばす
        ret = expression(begin);
        begin++; // ')'を読み飛ばす
    } else {
        ret = number(begin);
    }
    return ret;
}
int term(State &begin) {
    int ret = factor(begin);

    while (true) {
        if (*begin == '*') {
            begin++;
            ret *= factor(begin);
        } else if (*begin == '/') {
            begin++;
            ret /= factor(begin);
        } else {
            break;
        }
    }
    return ret;
}

int expression(State &begin) {
    int ret = term(begin);

    while (true) {
        if (*begin == '+') {
            begin++;
            ret += term(begin);
        } else if (*begin == '-') {
            begin++;
            ret -= term(begin);
        } else {
            break;
        }
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    cin.ignore(); // cin と getline を同時に使うため

    rep(i, n) {
        string s;
        getline(cin, s);

        State begin = s.begin();
        int ans = expression(begin);
        cout << ans << endl;
    }
    return 0;
}

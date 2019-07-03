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
LL number(State &begin);
LL factor(State &begin);
LL term(State &begin);
LL expr(State &begin);
LL number(State &begin) {
    LL ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}
LL factor(State &begin) {
    LL ret = 0;
    if (*begin == '(') {
        begin++;
        ret = expr(begin);
        begin++;
    } else {
        ret = number(begin);
    }
    return ret;
}
LL term
LL expr(State &begin) {
    LL ret = term(begin);
    while(true) {
        if (*begin == '+') {
            begin++;
            ret += term(begin);
        } else if (*begin == '-') {
            begin++;
            ret -= term(begin);
        } else if (*begin == '*') {
            begin++;
            ret *= term(begin);
        } else {
            break;
        }
    }
}
int main() {
    string str;
    getline(cin, str);
    State begin = str.begin();
    cout << expr(begin) << endl;
}

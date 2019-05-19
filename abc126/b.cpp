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
    string str;
    cin >> str;
    // int right = (str[2] - '0') * 10 + (str[3] - '0');
    // int left =  (str[0] - '0') * 10 + (str[1] - '0');
    string right = str.substr(2, 2);
    string left = str.substr(0, 2);
    if (left >= "01" and left <= "12"
        and right >= "01" and right <= "12" ){
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    else if (right >= "01" and right <= "12"
        and left >= "00" and left <= "99") {
        cout << "YYMM" << endl;
        return 0;
    } else if (left >= "01" and left <= "12"
               and right >= "00" and right <= "99") {
        cout << "MMYY" << endl;
        return 0;
    } else {
        cout << "NA" << endl;
        return 0;
    }
    return 0;
}

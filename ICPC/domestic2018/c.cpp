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

int main() {

    while (true) {
        LL b;
        cin >> b;
        if (b == 0) break;

        LL sum = 0;
        LL left = 1;
        LL right = 1;
        while (sum != b) {
            if (sum > b) {
                sum -= left++;
            }
            if (sum < b) {
                sum += right++;
            }
        }
        cout << left << " "  << right - left << endl;
    }
    return 0;
}

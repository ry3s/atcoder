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
    int N, L;
    cin >> N >> L;

    int right = L + N - 1;
    int eat;
    if (right <= 0) eat = right;
    else if (L >= 0) eat = L;
    else eat = 0;

    int ans = (right + L) * (right - L + 1) / 2 - eat;
    cout << ans << endl;
    return 0;
}

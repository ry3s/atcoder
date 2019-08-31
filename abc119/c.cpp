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
void chmin(int &a, int b) { if (a > b) a = b; }
using namespace std;
using LL = long long int;
using ULL = unsigned long long;
const int INF = 1e9;
int N, A, B, C;
vector<int> L;
int rec(int i, int a, int b, int c) {
    if (i == N) {
        if (not a or not b or not c) return INF;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }
    int res = rec(i + 1, a, b, c);

    chmin(res, rec(i + 1, a + L[i], b, c) + (a ? 10 : 0));
    chmin(res, rec(i + 1, a, b + L[i], c) + (b ? 10 : 0));
    chmin(res, rec(i + 1, a, b, c + L[i]) + (c ? 10 : 0));
    return res;
}
int main() {
    cin >> N  >> A >> B >> C;
    L.resize(N);
    rep(i, N) {
        cin >> L[i];
    }

    cout << rec(0, 0, 0, 0) << endl;
}

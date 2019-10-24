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

int main() {
    int N; long long T; cin >> N >> T;
    vector<long long> ts(N);
    rep(i, N) cin >> ts[i];

    long long prev_time = 0;
    long long acc = 0;
    for (const auto t: ts) {
        long long diff = t - prev_time;
        if (diff <= T) {
            acc += diff;
        } else {
            acc += T;
        }
        prev_time = t;
    }
    acc += T;
    cout << acc << endl;
}

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
    long long n, m; cin >> n >> m;
    vector<long long> A(n);
    rep(i, n) cin >> A[i];

    sort(A.begin(), A.end(), greater<>());

    int cnt = m;
    int right = 0;
    long long sum = 0;
    for (int left = 0; left < n; left++ && cnt > 0) {
        while (right < n
               && cnt > 0
               && A[left + 1] + A[left + 2] < A[left] + A[right]) {
            sum += (A[left] + A[right]) * 2;
            right += 2;
            cnt -= 2;
        }
        right = left + 1;
    }
    cout << cnt << endl;
    cout << sum << endl;
}

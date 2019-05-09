#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

int main() {
  LL n, k, x, ans = 2000000001;

  cin >> n >> k;
  vector<LL> v, deff;
  rep(i, n) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());

  rep(i, n - k + 1) {
    LL h_min = v[i];
    LL h_max = v[i + k - 1];
    LL diff = h_max - h_min;
    ans = min(diff, ans);
  }
  cout << ans << endl;
  return 0;
}

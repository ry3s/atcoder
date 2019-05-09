#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <utility>
#include <cstdio>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

int main() {
  int N;
  LL x, y, h, px, py, ph;
  LL H, X, Y;
  vector<tuple<LL, LL, LL> >  v;
  cin >> N;
  rep(i, N) {
    cin >> x >> y >> h;
    v.push_back(make_tuple(x, y, h));
  }
  
  rep(Cx, 101) {
    rep(Cy, 101) {
      int H = -1;
      int Hmax = 2e9;
      bool success = true;
      rep(i, N) {
        tie(x, y, h) = v[i];
        int d = abs(Cx - x) + abs(Cy - y);
        if (h > 0) {
          int H2 = h + d;
          if (H > 0 and H != H2) {
            success = false;
            break;
          } else {
            H = H2;
          }
        } else {
          Hmax = min(Hmax, d);
        }
      }
      if (success and H <= Hmax) {
        cout << Cx << " " << Cy << " " << H <<endl;
        return 0;
      }
    }
  }
  return 0;
}

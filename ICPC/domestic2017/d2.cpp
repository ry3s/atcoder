#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define pb push_back

int N, M;
string B[514];
bool E[514];
int dp[1 << 24][2];

//N < M
void mode1() {
  int ans = 0;
  rep(i, 1 << N) {
    rep(j, M)E[j] = false;
    int cnt = 0;
    rep(j, N) {
      if (i >> j & 1) { //use No.j
        cnt++;
        rep(k, M) {
          if (B[j][k] == '1')E[k] = !E[k];
        }
      }
    }
    bool flag = true;
    rep(j, M)if (E[j])flag = false;
    if (flag) ans = max(ans, cnt);
  }
  cout << ans << endl;
}

//N >= M
void mode2() {
  rep(i, 1 << M)dp[i][0] = -1;
  dp[0][0] = 0;
  bool k = 1;
  rep(i, N) {
    int W = 0;
    int d = 1;
    rep(j, M) { //入力を2進数に変換
      W += d * (B[i][M - j - 1] == '1');
      d *= 2;
    }
    rep(j, 1 << M)dp[j][k] = dp[j][!k];
    rep(j, 1 << M) {
      if (dp[j][!k] >= 0) {
        int x = j^W;
        dp[x][k] = max(dp[j][!k] + 1, dp[x][k]);
      }
    }
    k = !k;
  }
  cout << dp[0][!k] << endl;
}

int main() {
  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0)return 0;
    rep(i, N) cin >> B[i];
    if (N < M)
      mode1();
    else
      mode2();
  }
}

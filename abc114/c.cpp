#include <iostream>
#include <map>
#include <string>
#include <cmath>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

// 012 <--> 753
const string i2c = "753";
const map<char, int> c2i = {{'7', 0}, {'5', 1}, {'3', 2}};
int main() {
  int n;

  cin >> n;

  int ans = 0;;
  for (int d = 3; d < 10; d++) {
    for(int b = 0; b < pow(3, d); b++) {
      string str;

      int cb = b;

      for (int i = 0; i < d; i++) {
        str.push_back(i2c[cb % 3]);
        cb /= 3;
      }

      bool cnt[3];
      fill(cnt, cnt+3, false);

      for (char c : str) {
        cnt[c2i.at(c)] = true;
      }

      bool judge = true;
      rep(i, 3) {
        if (not cnt[i]) judge = false;
      }
      if (not judge) continue;

      if (stoi(str) <= n) ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}

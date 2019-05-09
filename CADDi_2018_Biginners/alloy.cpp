#include <iostream>

using namespace std;

int main() {
  int n, h, w;
  int a, b;
  int sum = 0;
  cin >> n >> h >> w;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a >= h && b >= w) {
      sum += 1;
    }
  }

  cout << sum << endl;
  return 0;
}

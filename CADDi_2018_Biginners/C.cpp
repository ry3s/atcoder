#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long n, p;
  long long i = 0;
  long long ans;
  cin >> n >> p;
  if (n == 1) {
    cout << p << endl;
  } else if (p == 1) {
    cout << "1" << endl;
  } else if (n > 64) {
    cout << "1" << endl;
  } else {
    ans = 1;
    i = 2;
      
    while (pow(i, n) <= p) {
      if (p % (long long)pow(i, n) == 0){
        ans = i;
      }
      i++;
    }
    cout << ans << endl;
  }

  return 0;
}

#include <iostream>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
typedef long long int LL;

int main() {
  LL a, b, c;
  cin >> a >> b >> c;
  if (a + b < c) {
    cout << a+b+1+b << endl;
  } else {
    cout << b + c << endl;
  }
  return 0;
}

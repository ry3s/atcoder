#include <iostream>

using namespace std;

int main() {
  string n;
  int sum = 0;
  cin >> n;
  if (n[0] == '2') sum++;
  if (n[1] == '2') sum++;
  if (n[2] == '2') sum++;
  if (n[3] == '2') sum++;

  cout << sum << endl;
  return 0;
}
  

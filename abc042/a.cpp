#include <iostream>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;

    if ((a == 7 && b == 5 && c == 5)
        || (a == 5 && b == 7 && c == 5)
        || (a == 5 && b == 5 && c == 7)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

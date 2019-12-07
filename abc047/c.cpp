#include <iostream>
#include <string>
using namespace std;

int main() {
    string str; cin >> str;

    auto first = str.begin();
    auto last = str.end();
    int cnt = 0;
    while (first != prev(last)) {
        if (*first != *(next(first))) {
            cnt++;
        }
        first++;
    }
    cout << cnt << endl;
}
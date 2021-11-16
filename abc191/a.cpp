#include <iostream>

int main() {
    int v,t, s, d;
    std::cin >> v >> t >> s >> d;
    if (d >= v * t && d <= v * s) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
}

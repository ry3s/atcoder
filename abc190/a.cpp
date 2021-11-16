#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a < b) {
        std::cout << "Aoki" << std::endl;
    } else if (a > b){
        std::cout << "Takahashi" << std::endl;
    } else {
        if (c == 0) {
            std::cout << "Aoki" << std::endl;
        } else {
            std::cout << "Takahashi" << std::endl;
        }
    }
}

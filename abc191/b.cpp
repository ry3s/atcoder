#include <iostream>
#include <vector>

int main() {
    int64_t n, x;
    std::cin >> n >> x;

    std::vector<int64_t> ans;
    for (int i = 0; i < n; i++) {
        int64_t y;
        std::cin >> y;
        if (y == x) continue;;
        ans.push_back(y);
    }

    for (const auto v: ans) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

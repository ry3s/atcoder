#include <iostream>
#include <vector>
#include <string>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> s;

    for (int i = 0; i < h; i++) {
        std::string t;
        std::cin >> t;
        s.push_back(t);
    }
    int ans = 0;
    for (int y = 1; y < h; y++) {
        for (int x = 1; x < w; x++) {
            int count = (s[y][x] == '#') + (s[y - 1][x] == '#')
                + (s[y][x - 1] == '#') + (s[y - 1][x - 1] == '#');
            if (count == 3 || count == 1) {
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
}

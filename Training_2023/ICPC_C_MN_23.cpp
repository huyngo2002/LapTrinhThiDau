#include <iostream>
#include <vector>
#include <unordered_map>
#define int long long
struct Triple {
    int x, y, z;
};
int n, k, res;
std::vector<Triple> oxy;
std::vector<Triple> oxz;
std::vector<Triple> oyz;
int32_t main() {
    std::cin >> n >> k;
    res = n * k;
    for (int i = 0, x, y, z; i < k; i++) {
        std::cin >> x >> y >> z;
        if (x == 0) {
            oyz.push_back({x, y, z});
        }
        if (y == 0) {
            oxz.push_back({x, y, z});
        }
        if (z == 0) {
            oxy.push_back({x, y, z});
        }
    }
    std::vector<Triple> ans;
    for (const auto& i : oxy) {
        for (const auto& j : oxz) {
            if (i.x == j.x) {
                ans.push_back({i.x, i.y, j.z});
            }
        }
        for (const auto& j : oyz) {
            if (i.y == j.y) {
                ans.push_back({i.x, i.y, j.z});
            }
        }
    }
    for (const auto& i : oxz) {
        for (const auto& j : oyz) {
            if (i.z == j.z) {
                ans.push_back({i.x, j.y, i.z});
            }
        }
    }
    std::unordered_map<int, int> cnt;
    for (const auto& t : ans) {
        cnt[t.x * 10000 + t.y * 100 + t.z]++;
    }
    int s = 0;
    for (const auto& p : cnt) {
        if (p.second > 2) {
            s++;
        }
    }
    std::cout << res - ans.size() + s;
    return 0;
}

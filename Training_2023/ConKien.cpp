#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Hàm đệ quy để tính số cách di chuyển
int countWays(int n, long long k, bool isTop) {
    // Trường hợp cơ bản
    if (k == 0) {
        // Nếu con kiến ở đỉnh sau k bước đi, trả về 1 nếu đỉnh đó là đỉnh ban đầu, ngược lại trả về 0
        return isTop ? 1 : 0;
    }

    // Tính số cách di chuyển từ đỉnh
    int fromTop = countWays(n, k-1, true) * (n-1);

    // Tính số cách di chuyển từ đáy
    int fromBottom = countWays(n, k-1, false) * 2;

    // Tổng số cách di chuyển là tổng của số cách di chuyển từ đỉnh và từ đáy
    int total = (fromTop + fromBottom) % MOD;

    return total;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    // Gọi hàm và in kết quả
    int result = countWays(n, k, true);
    cout << result << endl;

    return 0;
}

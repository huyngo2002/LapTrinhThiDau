#include <iostream>

using namespace std;

int find_magical_number(int A, int B, int C, int D) {
    for (int n = 1; n <= 1e9; n++) {
        if (n % A == 0 && B % n != 0 && C % n == 0 && D % n != 0) {
            return n;
        }
    }
    return -1;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int result = find_magical_number(A, B, C, D);

    cout << result << endl;

    return 0;
}

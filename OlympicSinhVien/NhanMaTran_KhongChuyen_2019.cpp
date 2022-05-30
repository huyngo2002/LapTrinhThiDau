//Link: https://oj.vnoi.info/problem/olp_kc19_mat 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 110;
int k, n, I, J;
ll S;
ll a[N][N], b[N][N], c[N];
ll mulmod(ll a, ll b, ll m) {
    if (b == 0) return 0;
    long long res = mulmod(a, b / 2, m);
    res = res * 2 % m;
    if (b % 2) res = (res + (a * (b - (b / 2) * 2))) % m;
    return res;
}

int main() {
    cin >> k >> n >> I >> J >> S;
    I--;
    J--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] %= S;
        }
    }
    for (int o = 1; o < k; o++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            c[j] = 0;
            for (int i = 0; i < n; i++) {
                c[j] += mulmod(a[I][i], b[i][j], S);
                c[j] %= S;
            }
        }
        for (int j = 0; j < n; j++) {
            a[I][j] = c[j];
        }
    }
    cout << (a[I][J] + S) % S;
    return 0;
}

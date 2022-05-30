// Link: https://oj.vnoi.info/problem/olp_kc20_cows
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, S, T;
    cin>>n>>S;
    while(n!=0)
    {
        T+=n;
        n--;
    }
    cout<<T-S;
    return 0;
}

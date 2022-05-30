// Link: https://oj.vnoi.info/problem/olp_ct20_reflective
#include <bits/stdc++.h>
using namespace std;
int64_t f(int64_t x)
{
    int64_t sum=0;
    while(x > 0)
    { x>>=1; sum += x;}
    return sum;
}
int main()
{
    int64_t lf,rt;
    cin>>lf>>rt;
    cout<<f(rt)-f(lf-1);
}

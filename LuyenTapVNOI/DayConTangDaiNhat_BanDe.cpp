// Link:  https://oj.vnoi.info/problem/liq
#include <bits/stdc++.h>
using namespace std;
void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int i = 0; i < a.size(); i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
}

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n): n(n), f(n+1, 0) {}
    void set(int x, int i) {
        for (; i<=n; i += i&(-i)) f[i] = max(f[i], x);
    }
    int get(int i) const {
        int r = 0;
        for (; i>=1; i -= i&(-i)) r = max(r, f[i]);
        return r;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    compress(a);

    Fenwick bit(n);
    for (int i = 0; i < n; i++) bit.set(bit.get(a[i]-1) + 1, a[i]);

    cout << bit.get(n);
    return 0;
}
/*
#include <iostream>
#include <stdlib.h>
using namespace std;

int n;

int main()
{
    cin>>n;
    int a[n];
    int l[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    l[0]=1;
    int lmax;

    for(int i=1; i<n; i++)
    {
        lmax=0;
        for(int j=0; j<i; j++)
        {
            if (a[i]>a[j])
                if(l[j]>lmax)
                    lmax = l[j];

        }
        l[i]= lmax+1;
    }
    int lengMax=0;
    for(int i=0; i<n; i++)
        if(l[i]>lengMax)
            lengMax=l[i];
    cout<<lengMax;
    return 0;
}*/

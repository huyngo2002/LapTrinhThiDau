/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;
#pragma GCC optimize("Ofast")
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,a,b;
pa fnd(int x){
    --x;
    return make_pair(x/m,x%m);
}
int main(){
    cin>>n>>m>>a>>b;
    pa sola=fnd(a), solb=fnd(b);
    if(m==1){
        cout<<"1\n0 "<<sola.fi<<" 1 "<<solb.fi+1;
        return 0;
    }
    if(sola.fi==solb.fi){
        cout<<"1\n";
        cout<<sola.se<<' '<<sola.fi<<' '<<solb.se+1<<' '<<sola.fi+1;
        return 0;
    }
    int lastrow=fnd(n).fi;
    if(b==n) solb.se=m-1;
    if(!sola.se){
        if(solb.se==m-1){
            cout<<"1\n"<<0<<' '<<sola.fi<<' '<<m<<' '<<solb.fi+1;
            return 0;
        }
        else{
            cout<<"2\n";
            cout<<"0 "<<sola.fi<<' '<<m<<' '<<solb.fi<<'\n';
            cout<<"0 "<<solb.fi<<' '<<solb.se+1<<' '<<solb.fi+1;
            return 0;
        }
    }
    if(sola.fi+1==solb.fi){
        cout<<"2\n";
        cout<<sola.se<<' '<<sola.fi<<' '<<m<<' '<<sola.fi+1<<'\n';
        cout<<0<<' '<<solb.fi<<' '<<solb.se+1<<' '<<solb.fi+1;
        return 0;
    }
    if(sola.se==solb.se+1){
        cout<<"2\n";
        cout<<sola.se<<' '<<sola.fi<<' '<<m<<' '<<solb.fi<<'\n';
        cout<<0<<' '<<sola.fi+1<<' '<<solb.se+1<<' '<<solb.fi+1<<'\n';
        return 0;
    }
    if(solb.se==m-1){
        cout<<"2\n";
        cout<<sola.se<<' '<<sola.fi<<' '<<m<<' '<<sola.fi+1<<'\n';
        cout<<0<<' '<<sola.fi+1<<' '<<m<<' '<<solb.fi+1<<'\n';
        return 0;
    }
    else{
        cout<<"3\n";
        cout<<sola.se<<' '<<sola.fi<<' '<<m<<' '<<sola.fi+1<<'\n';
        cout<<0<<' '<<sola.fi+1<<' '<<m<<' '<<solb.fi<<'\n';
        cout<<0<<' '<<solb.fi<<' '<<solb.se+1<<' '<<solb.fi+1<<'\n';
        return 0;
    }
    return 0;
}



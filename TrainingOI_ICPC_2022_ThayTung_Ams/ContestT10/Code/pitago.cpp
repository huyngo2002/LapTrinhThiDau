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
const int MN = 1e4 + 5;
int n, a[MN];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] *= a[i];
	}
	sort(a + 1, a + 1 + n);
	int l, ans = 0, r;
	for (int i = 3; i <= n; i++){
		l = 1;
		r = i - 1;
		while (l < r) {
			if (a[l] + a[r] == a[i]){
				ans++;
				l++;
			   	r--;
			}else if (a[l] + a[r] < a[i]){
				l++;
			}else{
				r--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}


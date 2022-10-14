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
struct element {
	int maxSum, maxLeft, maxRight;
};
int n, numQuery;
int a[100005];
priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq;
vector <std::pair <int, int> > listQuery;
int ans[100005];
element it[4 * 100005];

void update(int index, int L, int R, int pos, int value) {
	if (L > pos || R < pos) {
		return;
	}
	if (L == R) {
		it[index] = (element) {
			1, 1, 1
		};
		return;
	}
	int mid = (L + R) / 2;
	update(2 * index, L, mid, pos, value);
	update(2 * index + 1, mid + 1, R, pos, value);
	if (it[2 * index].maxLeft == mid - L + 1) {
		it[index].maxLeft = it[2 * index].maxLeft + it[2 * index + 1].maxLeft;
	} else {
		it[index].maxLeft = it[2 * index].maxLeft;
	}
	if (it[2 * index + 1].maxRight == R - mid) {
		it[index].maxRight = it[2 * index + 1].maxRight + it[2 * index].maxRight;
	} else {
		it[index].maxRight = it[2 * index + 1].maxRight;
	}
	it[index].maxSum = std::max(it[2 * index].maxSum, std::max(it[2 * index + 1].maxSum, it[2 * index].maxRight + it[2 * index + 1].maxLeft));
}

int main () {
	ios::sync_with_stdio(false);
	cin >> n >> numQuery;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pq.push(std::make_pair(a[i], i));
	}
	for (int i = 1; i <= numQuery; i++) {
		int value;
		cin >> value;
		listQuery.push_back(std::make_pair(value, i));
	}
	sort(listQuery.begin(), listQuery.end());
	for (int i = 0; i < (int) listQuery.size(); i++) {
		while (!pq.empty()) {
			pair <int, int> curElement = pq.top();
			if (curElement.first <= listQuery[i].first) {
				update(1, 1, n, curElement.second, curElement.first);
				pq.pop();
			} else {
				break;
			}
		}
		element ret = it[1];
		ans[listQuery[i].second] = ret.maxSum;
	}
	for (int i = 1; i <= numQuery; i++) {
		cout << ans[i] << std::endl;
	}
	return 0;
}


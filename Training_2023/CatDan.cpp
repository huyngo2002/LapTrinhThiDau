#include <iostream>
#include <vector>
#include <algorithm>
long long kc(int x1, int y1, int x2, int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
std::vector<long long> goc;
bool check(std::vector<long long> v){
	if (goc[0]==v[0]&&goc[1]==v[1]&&goc[2]==v[2]&&goc[3]==v[3]) return true;
	return false;
}
int x1, y1, x2, y2, x3, y3, x4, y4;
int t, cnt = 0;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	goc.push_back(kc(x1,y1,x2,y2));
	goc.push_back(kc(x2,y2,x3,y3));
	goc.push_back(kc(x3,y3,x4,y4));
	goc.push_back(kc(x4,y4,x1,y1));
	std::sort(goc.begin(), goc.end());
	std::cin >> t;
	while (t--){
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		std::vector<long long> temp;
		temp.push_back(kc(x1,y1,x2,y2));
		temp.push_back(kc(x2,y2,x3,y3));
		temp.push_back(kc(x3,y3,x4,y4));
		temp.push_back(kc(x4,y4,x1,y1));
		std::sort(temp.begin(), temp.end());
		if (check(temp)) cnt++;
	}
	std::cout << cnt;
	return 0;
}

#include <iostream>
#include <map>
//#include <pair>

// Cach 1:
std::map<long long, long long> cache;
long long f(long long n){
	if (cache.count(n) > 0) return cache[n];
	int k = n / 2;
	if (n & 1) return cache[n] = f(k + 1) * f(k + 1) + f(k) * f(k);
	else return cache[n] = f(k) * (f(k + 1) + f(k - 1));
}

// Cach 2:
std::pair<long long, long long> ff(long long n){
	if (n == 0) return {0, 1};
	auto fk = ff(n / 2);
	long long a = fk.first * (2 * fk.second - fk.first);
	long long b = fk.first * fk.first + fk.second * fk.second;
	if (n & 1) return {b, a + b};
	else return {a, b};
}
int main() {
	cache[0] = 0, cache[1] = 1, cache[2] = 1;
	//std::cout << f(1'000'000);
	int tt;
	for (int i = 1; i <= 10; ++i) 
		std::cout << ff(i).first << ' ';
	return 0;
}

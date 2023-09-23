#include <iostream>
#include <vector>
const int MOD = 1e9 + 7;
int cnt(int sum, const std::vector<int>& faces) {
    std::vector<int> dp(sum + 1, 0);
    dp[0] = 1; 
    for (int i = 1; i <= sum; i++) {
        for (int face : faces) {
            if (i - face >= 0) {
                dp[i] = (dp[i] + dp[i - face]) % MOD;
            }
        }
    }
    return dp[sum];
}
bool check(int day, int month, int year) {
    if (year < 1 || year > 1000000) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    int maxDay;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    } else {
        maxDay = 31;
    }
    if (day < 1 || day > maxDay) {
        return false;
    }

    return true;
}
int main() {
    std::string date;
    std::cin >> date;
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    if (!check(day, month, year)) std::cout << 0;
    else {
    	int sum = day + month + year;
    	std::vector<int> faces = {2, 4, 6, 8, 10};
    	int result = cnt(sum, faces);
    	std::cout << result;
	}
    return 0;
}

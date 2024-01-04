#include <iostream>
#include <vector>
int n, k;
std::vector<int> ans;
int main ()
{
    std::cin >> n >> k;
    if (n <= 9)
    {
        for (int i = 1; i <= k - 1; ++i)
        {
            std::cout << '1';
        }
        std::cout << n;
    }
    else
    {
        for (int i = 9; i >= 2; --i)
        {
            while (!(n % i))
            {
                ans.push_back(i);
                n /= i;
            }
        }
        if ((int)ans.size() > k or n != 1)
        {
            std::cout << -1;
        }
        else
        {
            for (int i = 1; i <= k - (int)ans.size(); ++i)
            {
                std::cout << '1';
            }
            for (int i = (int)ans.size() - 1; i >= 0; --i)
            {
                std::cout << ans[i];
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
int numTest, d, n;
const int MAX = 15;
int main()
{
    std::cin >> numTest;
    while(numTest--)
    {
        std::cin >> d >> n;
        std::cout << MAX << ' ' << MAX << std::endl;
        char mat[MAX + 1][MAX + 1];
        for (int i = 1; i <= MAX; i++)
        {
            for (int j = 1; j <= MAX; j++)
            {
                if (j % 4 == 1)
                {
                    mat[i][j] = 'A';
                }
                else
                {
                    mat[i][j] = 'C';
                }
            }
        }
        int m = n / 3;
        for (int i = 1; i <= MAX; i++)
        {
            for (int j = 1; j <= MAX; j++)
            {
                if (j % 2 == 0 && i >= 2 && i <= 14 && m > 0)
                {
                    mat[i][j] = 'B';
                    m--;
                }
            }
        }
        if (n % 3 == 1)
        {
            mat[1][2] = 'B';
        }
        if (n % 3 == 2)
        {
            mat[1][2] = 'B';
            mat[1][4] = 'B';
        }
        for (int i = 1; i <= MAX; i++)
        {
            for (int j = 1; j <= MAX; j++)
            {
                std::cout << mat[i][j];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

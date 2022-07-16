// Bài này dùng heap
// https://www.hackerrank.com/challenges/qheap1/problem?fbclid=IwAR3n2YhMjUSHWgKkCJn6e6EjA9wce5c2H8-VHY57e9XZw5OL-66MNmJt3gk
#include <bits/stdc++.h>
int numQ;
int main ()
{
    std::priority_queue <int, std::vector <int>, std::greater<int>> heap_min;
    std::priority_queue <int, std::vector <int>, std::greater<int>> heap_temp;
    std::cin >> numQ;
    while (numQ--)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            int k;
            std::cin >> k;
            heap_min.push(k);
        }
        if (type == 2)
        {
            int z;
            std::cin >> z;
            heap_temp.push(z);
        }
        if (type == 3)
        {
            while (!heap_temp.empty() && heap_min.top() == heap_temp.top())
            {
                heap_min.pop();
                heap_temp.pop();
            }
            std::cout << heap_min.top() << std::endl;
        }
    }
    return 0;
}

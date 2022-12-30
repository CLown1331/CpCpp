#ifndef solution_h
#define solution_h 1

#include <iostream>
#include <queue>
#include <algorithm>

namespace solution
{
    void Solve()
    {
        int t;
        std::cin >> t;
        while (t--) {
            int n, m;
            std::cin >> n >> m;
            std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
            for (int i = 0; i < n; i++) {
                int x;
                std::cin >> x;
                pq.push(x);
            }
            for (int i = 0; i < m; i++) {
                int x;
                std::cin >> x;
                pq.pop();
                pq.push(x);
            }
            long long ans = 0;
            while (!pq.empty())
            {   
                ans += pq.top();
                pq.pop();
            }
            std::cout << ans << "\n";
        }
    }
}
#endif
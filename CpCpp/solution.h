#ifndef solution_h
#define solution_h 1

#include <iostream>
#include <queue>
#include <algorithm> 

namespace solution
{
    using namespace std;

    void Solve()
    {
        int t, n;
        cin >> t;
        while (t--) {
            cin >> n;
            cerr << n << ": --> \n";
            if (n == 3) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                if (n & 1) {
                    for (int i = 0; i < n; i++) {
                        if (i & 1) cout << ((n - 1) / 2) << " ";
                        else cout << -(((n - 1) / 2) - 1) << " ";
                    }
                    cout << "\n";
                }
                else {
                    for (int i = 0; i < n; i++) {
                        if (i & 1) cout << "-";
                        cout << 1 << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }
}
#endif
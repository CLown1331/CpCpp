#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#ifndef BpmHopcraft_h
#define BpmHopcraft_h 1
namespace library
{
const int MAXN1 = 50010; // nodes in set a
const int MAXN2 = 50010; // nodes in set b
const int MAXM = 150010; // number of edges
struct BpmHopcraft
{
    int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
    int matching[MAXN2], dist[MAXN1], Q[MAXN1];
    bool used[MAXN1], vis[MAXN1]; // vis is cleared in each Dfs
    void Init(int _n1, int _n2)
    {
        n1 = _n1;
        n2 = _n2;
        edges = 0;
        std::fill(last, last + n1, -1);
    }
    void AddEdge(int u, int v)
    {
        head[edges] = v;
        prev[edges] = last[u];
        last[u] = edges++;
    }
    void Bfs()
    {
        std::fill(dist, dist + n1, -1);
        int sizeQ = 0;
        for (int u = 0; u < n1; ++u)
        {
            if (!used[u])
            {
                Q[sizeQ++] = u;
                dist[u] = 0;
            }
        }
        for (int i = 0; i < sizeQ; i++)
        {
            int u1 = Q[i];
            for (int e = last[u1]; e >= 0; e = prev[e])
            {
                int u2 = matching[head[e]];
                if (u2 >= 0 && dist[u2] < 0)
                {
                    dist[u2] = dist[u1] + 1;
                    Q[sizeQ++] = u2;
                }
            }
        }
    }
    bool Dfs(int u1)
    {
        vis[u1] = true;
        for (int e = last[u1]; e >= 0; e = prev[e])
        {
            int v = head[e];
            int u2 = matching[v];
            if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && Dfs(u2)))
            {
                matching[v] = u1;
                used[u1] = true;
                return true;
            }
        }
        return false;
    }
    int AugmentPath()
    {
        Bfs();
        std::fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && Dfs(u))
                ++f;
        return f;
    }
    int MaxMatching()
    {
        std::fill(used, used + n1, false);
        std::fill(matching, matching + n2, -1);
        for (int res = 0;;)
        {
            int f = AugmentPath();
            if (!f)
                return res;
            res += f;
        }
    }
};
} // namespace library
#endif
#ifndef solution_h
#define solution_h 1
namespace solution
{
using namespace std;
const int sz = 1005;
library::BpmHopcraft bpm;
void Solve()
{
    int t, n, m;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        scanf("%d %d", &n, &m);
        bpm.Init(n, n);
        while (m--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            bpm.AddEdge(x, y);
            bpm.AddEdge(y, x);
        }
        printf("Case %d: %d\n", cs, n - (bpm.MaxMatching() / 2));
    }
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char *argv[])
{
    solution::Solve();
    return 0;
}

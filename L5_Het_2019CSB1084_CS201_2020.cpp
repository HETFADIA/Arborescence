#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define lld long long
#define int long long
#define p(x) cout << x << "\n";
#define p2(x, y) cout << x << " " << y << "\n";
#define p3(x, y, z) cout << x << " " << y << " " << z << "\n";
#define ps(x) cout << x << " ";
#define ps2(x, y) cout << x << " " << y << " ";
#define ps3(x, y, z) cout << x << " " << y << " " << z << " ";
#define pns(x) cout << x;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define dll(x) x.begin(), x.end(), greater<lld>()
#define vect(x, n) vector<lld> x(n, 0);
#define matrix(x, n, m) vector<vector<lld>> x(n, vector<lld>(m, 0));
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define lb lower_bound
#define ub upper_bound
#define pb(x) push_back(x);
#define pf(x) push_front(x);
#define mkp(x, y) make_pair(x, y)
#define inf 1e14
int min(vector<int> v)
{
    int res = 0;
    if (v.size())
    {
        res = v[0];
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (res > v[0])
        {
            res = v[0];
        }
    }
    return res;
}
int index(vector<int> v, int val)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == val)
        {
            return i;
        }
    }
    return 0;
}
void msa(set<int> V, set<pair<int, int>> E, int r, map<pair<int, int>, int> w)
{
    set<pair<int, int>> edges_copy;
    for (auto i = E.begin(); i != E.end(); i++)
    {
        int u = i->first;
        int v = i->second;
        edges_copy.insert({u, v});
    }
    for (auto i = edges_copy.begin(); i != edges_copy.end(); i++)
    {
        int u = i->first;
        int v = i->second;
        if (v == r)
        {
            E.erase({u, v});
            w.erase({u, v});
        }
    }
    map<int, int> pi;
    for (auto i = V.begin(); i != V.end(); i++)
    {
        int v = *i;
        vector<int> edgesa;
        for (auto j = E.begin(); j != E.end(); j++)
        {
            if (j->second == v)
            {
                edgesa.pb(j->first);
            }
        }
        vector<int> cost;
        for (int theta = 0; theta < edgesa.size(); theta++)
        {
            int u = edgesa[theta];
            int costa = w[{u, v}];
            cost.pb(costa);
        }
        int min_costa = min(cost);
        int indexa = index(cost, min_costa);
        pi[v] = edgesa[cost[indexa]];
    }
    int cycle_vertex = inf;
    for (auto i = V.begin(); i != V.end(); i++)
    {
        int v = *i;
        if (cycle_vertex != inf)
        {
            break;
        }
        set<int> visited;
        int next_v = pi[v];
        auto finded = pi.find(v);
        if (finded == pi.end())
        {
            next_v = inf;
        }
        while (next_v != inf)
        {
        }
    }
}
void arborescence()
{
    int n, m, s;
    int u, v, w;
    cin >> n >> m >> s;
    set<int> vertex;
    set<pair<int, int>> edges;
    map<pair<int, int>, int> wt;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        vertex.insert(v);
        edges.insert({u, v});
        wt[{u, v}] = w;
    }
    msa(vertex, edges, s, wt);
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        arborescence();
    }
}
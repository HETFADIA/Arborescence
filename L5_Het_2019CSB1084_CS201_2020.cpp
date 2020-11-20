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
#define ps4(x, y, z, a) cout << x << " " << y << " " << z << " " << a << " ";
#define ps5(x, y, z, a, b) cout << x << " " << y << " " << z << " " << a << " " << b << " ";
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
void copy(set<pair<int, int>> real, set<pair<int, int>> &virtuala)
{
    for (auto i = real.begin(); i != real.end(); i++)
    {
        int fi = i->first;
        int se = i->second;
        virtuala.insert({fi, se});
    }
}
int min(vector<int> v)
{
    int res = 0;
    if (v.size())
    {
        res = v[0];
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (res > v[i])
        {
            res = v[i];
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
int get(map<int, int> pi, int val)
{
    auto finder = pi.find(val);
    if (finder == pi.end())
    {
        return inf;
    }
    return pi[val];
}
int present(set<int> seta, int val)
{
    auto finder = seta.find(val);
    if (finder == seta.end())
    {
        return 0;
    }
    return 1;
}
int present(set<pair<int, int>> seta, pair<int, int> tuple)
{
    auto finder = seta.find(tuple);
    if (finder == seta.end())
    {
        return 0;
    }

    return 1;
}
int present(map<int, int> mapa, int val)
{
    auto finder = mapa.find(val);
    if (finder == mapa.end())
    {
        return 0;
    }
    return 1;
}
void print(vector<int> v)
{
    for (int i = 0; i != v.size(); i++)
    {
        ps(v[i]);
    }
    p("");
}
void prints(vector<int> v)
{
    for (int i = 1; i != v.size(); i++)
    {
        ps(v[i]);
    }
}
void print(set<pair<int, int>> seta)
{
    for (auto i = seta.begin(); i != seta.end(); i++)
    {
        ps2(i->first, i->second);
    }
    p("");
}
void print(map<int, int> mapa)
{
    for (auto i = mapa.begin(); i != mapa.end(); i++)
    {
        ps4("{", i->first, i->second, "}");
    }
    p("");
}
void print(set<int> seta)
{
    for (auto i = seta.begin(); i != seta.end(); i++)
    {
        ps(*i);
    }
    p("");
}
void print(map<pair<int, int>, pair<int, int>> mapa)
{
    for (auto i = mapa.begin(); i != mapa.end(); i++)
    {
        ps4(i->first.first, i->first.second, i->second.first, i->second.second);
    }
}
void print(map<pair<int, int>, int> mapa)
{
    for (auto i = mapa.begin(); i != mapa.end(); i++)
    {
        ps5("{", i->first.first, i->first.second, i->second, "}");
    }
    p("");
}
void print(pair<int, int> tuple)
{
    p2(tuple.first, tuple.second);
}
int min_index(vector<int> cost)
{
    int index = 0;
    int min_cost = 0;
    if (cost.size())
    {
        min_cost = cost[0];
    }
    for (int i = 0; i < cost.size(); i++)
    {
        if (min_cost > cost[i])
        {
            min_cost = cost[i];
            index = i;
        }
    }
    return index;
}
void msa(set<int> V, set<pair<int, int>> E, int r, map<pair<int, int>, int> w, set<pair<int, int>> &answer)
{
    //Step 1 : Removing all edges that lead back to the root
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

    // Step 2 : Finding the minimum incoming edge for every vertex. O(n**2) but okay since it is
    // a small sized list
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
        if (!edgesa.size())
        {
            continue;
        }
        vector<int> cost;
        for (int theta = 0; theta < edgesa.size(); theta++)
        {
            int u = edgesa[theta];
            int costa = w[{u, v}];
            cost.pb(costa);
        }
        int indexa = min_index(cost);
        pi[v] = edgesa[indexa];
    }

    // // //Step 3 : Finding cycles in the graph
    int cycle_vertex = inf;
    int next_v;
    for (auto i = V.begin(); i != V.end(); i++)
    {
        int v = *i;
        if (cycle_vertex != inf)
        {
            break;
        }
        unordered_set<int> visited;
        next_v = get(pi, v);

        while (next_v != inf && next_v != 0)
        {

            auto finder = visited.find(next_v);
            if (finder != visited.end())
            {
                cycle_vertex = next_v;
                visited.erase(next_v);
                break;
            }
            visited.insert(next_v);
            next_v = get(pi, next_v);
        }
    }

    ////Step 4 : If there is no cycle, return all the minimum edges pi(v)
    if (cycle_vertex == inf)
    {
        // set<pair<int, int>> answera;
        answer.clear();
        for (auto i = pi.begin(); i != pi.end(); i++)
        {
            int v = i->first;
            pair<int, int> e = {pi[v], v};
            answer.insert(e);
        }
        return;
    }

    set<int> C;
    C.insert(cycle_vertex);
    next_v = get(pi, cycle_vertex);
    while (next_v != cycle_vertex)
    {
        C.insert(next_v);
        next_v = get(pi, next_v);
    }

    int v_c = -cycle_vertex * cycle_vertex;
    set<int> V_prime;
    for (auto theta = V.begin(); theta != V.end(); theta++)
    {
        int v = *theta;
        if (present(C, v) == 0)
        {
            V_prime.insert(v);
        }
    }
    V_prime.insert(v_c);

    set<pair<int, int>> E_prime;
    map<pair<int, int>, int> w_prime;
    map<pair<int, int>, pair<int, int>> correspondance;
    pair<int, int> e;
    for (auto i = E.begin(); i != E.end(); i++)
    {
        int u = i->first;
        int v = i->second;
        int wt=w[{u,v}];
        if (present(C, u) == 0 && present(C, v) == 1)
        {
            e = {u, v_c};
            if (present(E_prime, e) == 1)
            {
                if (w_prime[e] < wt - w[{pi[v], v}])
                {
                    continue;
                }
            }
            w_prime[e] = wt - w[{pi[v], v}];
            correspondance[e] = {u, v};
            E_prime.insert(e);
        }
        else if (present(C, u) == 1 && present(C, v) == 0)
        {

            e = {v_c, v};
            if (present(E_prime, e) == 1)
            {
                auto elementa = correspondance[e];
                int old_u = elementa.first;
                if (w[{old_u, v}] < wt)
                {

                    continue;
                }
            }
            E_prime.insert(e);
            w_prime[e] = wt;
            correspondance[e] = {u, v};
        }
        else if (present(C, u) == 0 && present(C, v) == 0)
        {
            e = {u, v};
            E_prime.insert(e);
            w_prime[e] = wt;
            correspondance[e] = {u, v};
        }
    }
    // print(V_prime);
    msa(V_prime, E_prime, r, w_prime, answer);
    pair<int, int> cycle_edge = {inf, inf};
    for (auto i = answer.begin(); i != answer.end(); i++)
    {
        int u = i->first;
        int v = i->second;
        if (v == v_c)
        {
            e = {u, v_c};
            auto elementa = correspondance[e];
            int old_v = elementa.second;
            cycle_edge = {pi[old_v], old_v};
            break;
        }
    }
    set<pair<int, int>> ret;
    for (auto i = answer.begin(); i != answer.end(); i++)
    {
        int u = i->first;
        int v = i->second;
        ret.insert(correspondance[{u, v}]);
    }
    for (auto i = C.begin(); i != C.end(); i++)
    {
        int v = *i;
        int u = pi[v];
        ret.insert({u, v});
    }
    ret.erase(cycle_edge);
    answer.clear();
    copy(ret, answer);
    // return ret;
}
int sum_finder(vector<set<pair<int, int>>> child, int source, vector<int> &distance)
{
    int suma = 0;
    for (auto i = child[source].begin(); i != child[source].end(); i++)
    {
        int wt = i->first;
        distance[i->second] = distance[source] + wt;
        suma += wt;
        suma += sum_finder(child, i->second, distance);
    }
    return suma;
}
void transfer_set_to_vector(set<pair<int, int>> answer, vector<set<pair<int, int>>> &child, vector<set<pair<int, int>>> &directparent, map<pair<int, int>, int> weight)
{
    for (auto i = answer.begin(); i != answer.end(); i++)
    {
        int u = i->first;
        int v = i->second;
        int w = weight[{u, v}];
        child[u].insert({w, v});
        directparent[v].insert({w, u});
    }
}
void print_parent(vector<set<pair<int, int>>> directparent, int n, int s)
{
    for (int i = 1; i <= n; i++)
    {
        if (directparent[i].size() != 0)
        {
            auto j = directparent[i].begin();
            ps(j->second);
        }
        else
        {
            ps(0);
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

    set<pair<int, int>> answer;
    vector<set<pair<int, int>>> child(n + 1);
    vector<set<pair<int, int>>> directparent(n + 1);
    msa(vertex, edges, s, wt, answer);
    transfer_set_to_vector(answer, child, directparent, wt);
    vector<int> distance(n + 1);

    distance[s] = 0;
    int sum = sum_finder(child, s, distance);
    ps(sum);
    prints(distance);
    ps("#");
    print_parent(directparent, n, s);
    p("");
}

signed main()
{
    fastio;
    clock_t start, end;
    start = clock();
    int t;
    cin >> t;

    while (t--)
    {
        arborescence();
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

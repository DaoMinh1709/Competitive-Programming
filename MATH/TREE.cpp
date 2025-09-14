#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;

struct TQuery
{
    int L, R, k, id;
} q[maxN];

vector<int> adj[maxN];
int cnt[maxN], pre[maxN];
int tin[maxN], tout[maxN];
int n, col[maxN], timer, t;
int ans[maxN], arr[maxN];

void DFS(int u = 1, int p = -1)
{
    tin[u] = ++timer;
    arr[timer] = col[u];
    for (int v : adj[u])
    {
        if (v == p) continue;
        DFS(v, u);
    }
    tout[u] = timer;
}

void ReadInput()    
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS();
    for (int i = 1; i <= t; i++)
    {
        int u; cin >> u >> q[i].k;
        q[i].L = tin[u];
        q[i].R = tout[u];
        q[i].id = i;
    }
    int SIZE = sqrt(n);
    sort(q + 1, q + t + 1, [&](TQuery x, TQuery y)
    {
        if (x.L / SIZE != y.R / SIZE) return x.L < y.L;
        return x.R < y.R;
    });
}

void Add(int i, int val)
{
    cnt[arr[i]] += val;
    if (val == -1)
        pre[cnt[arr[i]] + 1]--;
    else
        pre[cnt[arr[i]]]++;
}

void Solve()
{
    int l = 1, r = 0;
    for (int i = 1; i <= t; i++)
    {
        while (r < q[i].R) Add(++r, 1);
        while (l > q[i].L) Add(--l, 1);
        while (l < q[i].L) Add(l++, -1);
        while (r > q[i].R) Add(r--, -1);
        ans[q[i].id] = pre[q[i].k];
    }
    for (int i = 1; i <= t; i++)
        cout << ans[i] << '\n';
}

#define task ""
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    int T = 1;
    //cin >> T;
    while (T--)
    {
        ReadInput();
        Solve();
    }
}

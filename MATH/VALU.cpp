#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e6 + 1;   
const int MOD = 1e9 + 7;

struct Node
{
    int L, R, id;
};

int n, t, a[maxN], cnt[maxN];
ll ans[maxN], Sum;
Node q[maxN];

void ReadInput()    
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= t; i++)
    {
        cin >> q[i].L >> q[i].R; 
        q[i].id = i;
    }
    int SIZE = sqrt(n) + 0.5;
    sort(q + 1, q + t + 1, [&](Node x, Node y)
    {
        if (x.L / SIZE != y.L / SIZE) return x.L / SIZE < y.L / SIZE;
        return x.R < y.R;
    });
}

void Add(int i, int val)
{
    Sum -= (ll)cnt[a[i]] * cnt[a[i]] * a[i];
    cnt[a[i]] += val;
    Sum += (ll)cnt[a[i]] * cnt[a[i]] * a[i];
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
        ans[q[i].id] = Sum;
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;

struct TQuery
{
    ll L, R, id;
};

TQuery Q[maxN];
ll gt[maxN], gtm[maxN], ans[maxN];
ll q, Sum = 1;
ll l = 0, r = 1;

ll PowerMod(ll x, ll y)
{
    if (y == 0) return 1;
    ll t = PowerMod(x, y / 2);
    if (y % 2 == 0)
        return t * t % MOD;
    else
        return t * t % MOD * x % MOD;
}

ll C(ll k, ll n)
{
    //cout << gt[n] << ' ' << gtm[k] << ' ' << gtm[n - k];
    return (gt[n] * (gtm[k] * gtm[n - k] % MOD)) % MOD;
}

void AddL(int val)
{
    if (val == 1)
        Sum = (Sum + C(l + 1, r)) % MOD;
    else
        Sum = ((Sum - C(l, r)) % MOD + MOD) % MOD;
    l += val;
}

void AddR(int val)
{
    if (val == 1)
        Sum = ((Sum * 2 % MOD - C(l, r)) % MOD + MOD) % MOD;
    else
        Sum = ((Sum + C(l, r - 1)) % MOD * gtm[2]) % MOD;
    r += val;
}

void ReadInput()    
{
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i].L >> Q[i].R;
        Q[i].id = i;
    }
    ll p = sqrt(maxN - 1);
    sort(Q + 1, Q + q + 1, [&](const TQuery &x, const TQuery &y)
    {
        if (x.L / p != y.L / p) return x.L / p < y.L / p;
        return x.R < y.R;
    });
    gt[0] = gtm[0] = 1;
    for (ll i = 1; i < maxN; i++)
    {
        gt[i] = gt[i - 1] * i % MOD;
        gtm[i] = PowerMod(gt[i], MOD - 2);
    }
}

void Solve()
{
    for (int i = 1; i <= q; i++)
    {
        while (r < Q[i].R) AddR(1);
        while (l < Q[i].L) AddL(1);
        while (l > Q[i].L) AddL(-1);
        while (r > Q[i].R) AddR(-1);
        ans[Q[i].id] = Sum;
    }
    for (int i = 1; i <= q; i++)
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

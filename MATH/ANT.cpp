#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 2e7 + 1;   
const int MOD = 1e9 + 7;

ll n, m, gt[maxN];

void ReadInput()
{
    cin >> n >> m;
    gt[0] = 1;
    for (int i = 1; i < maxN; i++)
        gt[i] = gt[i - 1] * i % MOD;
}

ll PowMod(ll x, ll n)
{
    if (n == 0) return 1;
    ll t = PowMod(x, n / 2);
    if (n % 2 == 0)
        return t * t % MOD;
    else
        return t * t % MOD * x % MOD;
}

void Solve()
{
    ll x = 1, y = 1;
    for (int i = 0; i <= min(m, n); i++)
    {
        ll tmp = gt[m - i] * gt[n - i] % MOD * gt[i] % MOD;
        x = ((x * tmp % MOD) + (gt[m + n - i] * y % MOD)) % MOD; 
        y = y * tmp % MOD;
    }
    cout << x * PowMod(y, MOD - 2) % MOD - 1;
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

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 2e6  + 1;   
const int MOD = 1e9 + 7;

ll gt[maxN], x, n, res;
ll sieve[maxN];

void ReadInput()
{
    res = 1;
    cin >> x >> n;
}

ll PowerMod(ll a, ll b)
{
    if (b == 0) return 1;
    ll t = PowerMod(a, b / 2) % MOD;
    if (b % 2 == 0)
        return t * t % MOD;
    else
        return t * t % MOD * a % MOD;
}

void Calc(ll k)
{
    ll p = gt[n + k - 1];
    ll q = gt[n - 1] * gt[k] % MOD;
    ll a = p * PowerMod(q, MOD - 2) % MOD;
    res = (res * a) % MOD;
}

void Solve()
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ll k = 0;
            while (x % i == 0)
            {
                x /= i;
                k++;
            }
            Calc(k);
        }
    }
    if (x > 1) res = (res * n) % MOD;

    cout << res * PowerMod(2, n - 1) % MOD << '\n';
}

#define task ""
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    gt[0] = 1;
    for (ll i = 1; i < maxN; i++)
        gt[i] = gt[i - 1] * i % MOD;
    int T = 1;
    cin >> T;
    while (T--)
    {
        ReadInput();
        Solve();
    }
}

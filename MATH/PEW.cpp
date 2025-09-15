#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e6 + 1;   
const int MOD = 1e9 + 7;

string s;
ll gt[maxN], a[maxN], n, x, y;

void ReadInput()
{
    cin >> s;
    n = s.size();
    for (char c : s) a[c]++;
    gt[0] = 1;
    for (int i = 1; i < maxN; i++)
        gt[i] = (gt[i - 1] * i) % MOD;
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
    x = gt[n];
    y = 1;
    for (char c : s)
    {
        y = (y * gt[a[c]]) % MOD;
        a[c] = 1;
    }

    cout << x * PowMod(y, MOD - 2) % MOD;
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

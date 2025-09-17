#define task ""
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e5 + 10;
const int MOD = 1e9 + 7;

ll a, b, c, d;
ll X, Y;

ll gcd(ll u, ll v)
{
    if (v == 0) return u;
    return gcd(v, u % v);
}

void ReadInput()
{
    cin >> a >> b >> c;
    d = gcd(a, b);
}

void ExtGcd()
{
    ll m = a, n = b;
    ll xm = 1, xn = 0;
    while (n)
    {
        ll q = m / n;
        ll r = m - q * n;
        ll xr = xm - q * xn;

        m = n, xm = xn;
        n = r, xn = xr;
    }
    X = xm;
    Y = ((d - a * xm) / b);
}

void Solve()
{
    ExtGcd();
    ll t1, t2;
    t1 = -((c * X) / b);
    if (t1 >= 0) t1++;
    if ((c * X) % b == 0 && t1 < 0) t1++;
    t2 = (c * Y) / a;
    if (t2 < 0) t2--;
    if ((c * Y) % a == 0 && t2 >= 0) t2--;
    if (t1 > t2 || c % d != 0) cout << 0;
    else cout << t2 - t1 + 1;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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

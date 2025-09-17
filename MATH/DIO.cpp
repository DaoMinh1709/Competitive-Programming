#define task ""
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e5 + 10;
const int MOD = 1e9 + 7;

ll a, b, c;
ll m, n, r, q, xn, xm, xr;

void ReadInput()
{
    cin >> a >> b >> c;
}

ll gcd(ll u, ll v)
{
    if (v == 0) return u;
    return gcd(v, u % v);
}

ll FindX()
{
    m = a; n = b;
    xm = 1; xn = 0;
    while (n != 0)
    {
        q = m / n;
        r = m - n * q;
        xr = xm - q * xn;
        m = n; xm = xn;
        n = r; xn = xr;
    }
    return xm;
}

void Solve()
{
    ll d = gcd(a, b);
    ll x = FindX();
    ll y = (d - a * x) / b;
    cout << x << ' ' << y << '\n';
    ll tmp;
    if (x != 0)
        tmp = c / (a * x);
    else
        tmp = c / (b * y);
    x *= tmp; y *= tmp;
    cout << x << ' ' << y << '\n';
    ll kx = b / d;
    ll ky = a / d;
    cout << kx << ' ' << ky << '\n';
    if (x > y)
    {
        y = -y;
        ky = -ky;
        cout << (-x / kx) - (-y / ky) - 1;   
    }
    else
    {
        x = -x;
        kx = -kx;
        cout << (-y / ky) - (-x / kx) - 1;
    }
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;

ll a, b, c;

ll gcd(ll x, ll y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y)
{
    return x / gcd(x, y) * y;
}

void ReadInput()    
{
    cin >> a >> b >> c;
}

void Solve()
{
    cout << lcm(b / gcd(a, b), lcm(c / gcd(b, c), a / gcd(c, a))) << '\n';
}

#define task "MINX"
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(task".INP", "r", stdin);
    // freopen(task".OUT", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--)
    {
        ReadInput();
        Solve();
    }
}

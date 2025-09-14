#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e6 + 1;
const ll MOD = 1e9 + 7;

int n;
int L[maxN], R[maxN];
map<pair<int, int>, int> mp;

void ReadInput()
{
    mp.clear();
    for (int i = 1; i <= n; i++) cin >> L[i];
    for (int i = 1; i <= n; i++) cin >> R[i];
    for (int i = 1; i <= n; i++)
        mp[{L[i], R[i]}] = i;
}

bool Check(int l, int r)
{
    if (l > r || l < 1 || r > n) return true;
    //cerr << l << ' ' << r << '\n';
    if (!mp.count({l, r})) return false;
    int p = mp[{l, r}];
    if (!Check(l, p - 1)) return false;
    if (!Check(p + 1, r)) return false;
    return true;
}

ll PowerMod(ll x, ll y)
{
    if (y == 0) return 1;
    ll t = PowerMod(x, y / 2);
    if (y % 2 == 0)
        return t * t % MOD;
    else
        return t * t % MOD * x % MOD;
}

void Solve()
{
    if (!Check(1, n))
    {
        cout << 0 << '\n';
        return;
    }
    else
    {
        ll res = 1, tmp = 1;
        for (int i = 1; i <= n; i++)
        {
            res = (res * i) % MOD;
            tmp = tmp * (R[i] - L[i] + 1) % MOD;
        }
        //cout << res << ' ' << tmp;
        cout << res * PowerMod(tmp, MOD - 2) % MOD << '\n';
    }
}

#define task ""
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    int t = 0;
    while (cin >> n)
    {
        cout << "Case #" << ++t << ": ";
        ReadInput();
        Solve();
    }
}

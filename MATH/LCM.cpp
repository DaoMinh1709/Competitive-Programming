#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;

ll n;

void ReadInput()
{
    cin >> n;
}

void Solve()
{
    if (n % 2 == 0)
    {
        cout << n / 2 << ' ' << n / 2 << '\n';
    }
    else
    {
        ll res = 1;
        for (ll i = 1; i * i <= n; i++)
            if (n % i == 0)
            {
                if ((n - i) % i == 0 && n - i >= i)
                    res = max(res, i);
                if ((n - n / i) % (n / i) == 0 && n - n / i >= n / i)
                    res = max(res, n / i);
            }
        cout << res << ' ' << n - res << '\n';
    }
}

#define task ""
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--)
    {
        ReadInput();
        Solve();
    }
}

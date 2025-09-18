#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e6 + 1;

ll sieve[maxN], res = 0, n, m;
vector<ll> a;
void ReadInput()
{
    sieve[1] = 1;
    for (int i = 2; i * i <= maxN - 1; i++)
        if (!sieve[i])
            for (int j = i * i; j <= maxN - 1; j += i)
                sieve[j] = 1;
    cin >> n >> m;
}

ll calc(int t)
{
    ll s = 0;
    while (t > 0)
    {
        s += t % 10;
        t /= 10;
    }
    return s;
}

void Solve()
{
    for (int i = 1; i <= n; i++)
        if (!sieve[i])
            if (calc(i) == m)
            {
                res++;
                a.push_back(i);
            }
    cout << res << '\n';
    for (int i : a)
        cout << i << '\n';
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

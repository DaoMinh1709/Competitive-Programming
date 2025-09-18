#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e6 + 2;   
const int maxV = 1e6;

ll a[maxN], q, l, r, len = 0, sieve[maxN];

void ReadInput()
{
    cin >> q;
}

void Solve()
{
    for (int i = 2; i * i <= maxV; i++)
        if (sieve[i] == 0)
            for (int j = i * i; j <= maxV; j += i)
                sieve[j] = 1;
    sieve[3] = 1;
    for (ll i = 2; i <= maxV; i++)
        if (sieve[i] == 0)
            a[++len] = 3 * 3 * i * i;
        
    a[++len] = 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3;
    //for (int i = 1; i <= len; i++) cout << a[i] << ' ';
    while (q--)
    {
        cin >> l >> r;
        int x = lower_bound(a + 1, a + len + 1, l) - a;
        int y = upper_bound(a + 1, a + len + 1, r) - a - 1;
        cout << y - x + 1 << '\n';
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
    //cin >> T;
    while (T--)
    {
        ReadInput();
        Solve();
    }
}

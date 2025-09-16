#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e6 + 2;   
const int MOD = 1e9 + 7;

ll n, a[maxN];

void ReadInput()    
{
    cin >> n;
    for (int i = 1; i <= n; i++)    
        cin >> a[i];
}

ll gcd(ll x, ll y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

void Solve()
{
    if (n == 1 && abs(a[1]) == 1)
    {
        cout << -1;
        return;
    }
    int tmp = abs(a[1]);
    for (int i = 2; i <= n; i++)
        tmp = gcd(tmp, abs(a[i]));
    if (tmp > 1) 
    {
        cout << 0;
        return;
    }

    a[n + 1] = 0;
    int cnt = 0, res = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (abs(a[i]) % 2 == 1) cnt++;
        else
        {
            if (cnt % 2 == 0) res += cnt / 2;
            else res += cnt / 2 + 2;
            cnt = 0;
        }
    }
    cout << res;
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

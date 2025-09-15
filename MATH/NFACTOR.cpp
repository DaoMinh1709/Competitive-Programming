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

bool check(ll x)
{
    ll cnt = 0;
    while (x > 0 && cnt < n)
    {
        cnt += x / 5;
        x /= 5;
    }
    if (cnt < n) return false;
    return true;
}

void Solve()
{
    ll l = 1, r = 1e18;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << '\n';
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

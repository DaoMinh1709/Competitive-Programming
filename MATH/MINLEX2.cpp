#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int L, R, k;

void Solve()
{
    while (cin >> L >> R >> k)
    {
        string res = "~";
        for (int i = 1; i <= R; i *= 10)
        {
            int tmp = (max(i, L) + k - 1) / k * k;
            if (tmp <= R) res = min(res, to_string(tmp));
        }
        if (res == "~") res = "-1";
        cout << res << '\n';
    }
}

#define task ""
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    Solve();
}

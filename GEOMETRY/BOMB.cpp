#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;
const ld PI = atan(1) * 4;

struct TVector
{
    ll x, y;
    
    TVector operator - (const TVector &other) const
    {
        return {x - other.x, y - other.y};
    }
    ld operator * (const TVector &other) const
    {
        return (ld)x * other.y - (ld)other.x * y;
    }
};
using TPoint = TVector;

ld Len(TVector V)
{
    return sqrt(V.x * V.x + V.y * V.y);
}

bool CCW(TPoint A, TPoint B, TPoint C)
{
    return (B - A) * (C - B) > 0;
}

int n, R;
TPoint a[maxN], c[maxN];

void ReadInput()    
{
    cin >> n >> R;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
}

void Solve()
{
    TPoint A = *min_element(a + 1, a + n + 1, [&](const TPoint &B, const TPoint &C)
    {
        return (B.y < C.y) || (B.y == C.y && B.x < C.x);
    });
    sort(a + 1, a + n + 1, [&](const TPoint &B, const TPoint &C)
    {
        return (B - A) * (C - A) > 0 || (B - A) * (C - A) == 0 && Len(B - A) < Len(C - A);
    });

    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        while (m >= 2 && !CCW(c[m - 2], c[m - 1], a[i]))
            m--;
        c[m++] = a[i];
    }
    ld Peri = 0;
    Peri += Len(c[0] - c[m - 1]);
    for (int i = 1; i < m; i++)
        Peri += Len(c[i] - c[i - 1]);
    cout << fixed << setprecision(4) << Peri + 2 * R * PI;
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

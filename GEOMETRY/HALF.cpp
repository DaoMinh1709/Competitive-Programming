#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;

struct TVector
{
    ll x, y;
    
    ld operator * (const TVector &other) const
    {
        return x * other.y - other.x * y;
    }
    
    TVector operator - (const TVector &other) const
    {
        return {x - other.x, y - other.y};
    }
};
using TPoint = TVector;

ld Len(TVector V)
{
    return sqrt(V.x * V.x + V.y * V.y);
}

int n;
TPoint a[maxN];

void ReadInput()    
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
}

bool CCW(TPoint A, TPoint B, TPoint C)
{
    return (B - A) * (C - B) > 0;
}

void Solve()
{
    TPoint A = *min_element(a + 1, a + n + 1, [&](const TPoint &A, const TPoint &B)
    {
        if (A.y == B.y) return A.x < B.x;
        return A.y < B.y;
    });
    sort(a + 1, a + n + 1, [&](const TPoint &B, const TPoint &C)
    {
        return (B - A) * (C - A) > 0 || (B - A) * (C - A) == 0 && Len(B - A) < Len(C - A);
    });
    cout << a[1].x << ' ' << a[1].y << ' ' << a[n / 2 + 1].x << ' ' << a[n / 2 + 1].y << '\n';
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

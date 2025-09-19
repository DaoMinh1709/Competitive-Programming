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
    
    ll operator % (const TVector &other) const
    {
        return x * other.x + y * other.y;
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

bool CCW(TPoint A, TPoint B, TPoint C)
{
    return (B - A) * (C - B) > 0;
}

int n, m;
TPoint a[maxN], b[maxN];

void ReadInput()    
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i].x >> b[i].y;
}

TPoint A;
vector<TPoint> H;

int BS(TPoint P)
{
    int l = 1, r = n - 1, res = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if ((H[mid] - A) * (P - A) > 0)
        {
            l = mid + 1;
            res = mid;
        }
        else
            r = mid - 1;
    }
    return res;
}

bool Check(TPoint P)
{
    if (n == 1) return (P.x == A.x && P.y == A.y);
    //if (n == 2) return ((H[1] - H[0]) * (P - H[0]) == 0 && (H[1] - P) % (H[0] - P) <= 0); //WTF??
    if (n == 2) return ((H[1] - H[0]) * (P - H[0]) == 0 && (H[1] - H[0]) % (P - H[0]) <= 0);
    if (CCW(P, H[1], A) || CCW(A, H[n - 1], P)) return false;
    int i = BS(P);
    return !CCW(H[i + 1], H[i], P);
}

void Solve()
{
    A = *min_element(a + 1, a + n + 1, [&](const TPoint &A, const TPoint &B)
    {
        if (A.y == B.y) return A.x < B.x;
        return A.y < B.y;
    });
    sort(a + 1, a + n + 1, [&](const TPoint &B, const TPoint &C)
    {
        return (B - A) * (C - A) > 0 || (B - A) * (C - A) == 0 && Len(B - A) < Len(C - A);
    });
    for (int i = 1; i <= n; i++)
    {
        int sz = H.size();
        while (sz >= 2 && !CCW(H[sz - 2], H[sz - 1], a[i]))
        {
            H.pop_back();
            sz--;
        }
        H.push_back(a[i]);
    }
    n = H.size();
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (Check(b[i])) res++;
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

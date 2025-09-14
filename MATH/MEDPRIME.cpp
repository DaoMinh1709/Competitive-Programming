#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 2e5 + 10;
const int maxV = 10000 + 10;
const ll MOD = 1e9 + 7;

int n, cnt[maxN], b[maxV][15];

void ReadInput()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
}

void Solve()
{
    for (int i = 1; i < maxV; i++)
    {
        int tmp = i;
        for (int j = 2; j * j <= i; j++)
        {
            if (tmp % j == 0)
            {
                int x = 0;
                while (tmp % j == 0)
                {
                    tmp /= j;
                    x++;
                }
                b[j][x] += cnt[i];
                b[j][0] += cnt[i];
            }
        }
        if (tmp > 1)
        {
            b[tmp][1] += cnt[i];
            b[tmp][0] += cnt[i];
        }
    }
    for (int i = 1; i < maxV; i++)
        b[i][0] = n - b[i][0];

    int sum = 0, res = 1;
    for (int i = 1; i < maxV; i++)
    {
        int x = 0;
        for (int j = 0; j < 15; j++)
        {
            x += b[i][j];
            if (x >= (n + 1) / 2)
            {
                x = j;
                break;
            }
        }
        for (int j = 0; j < 15; j++)
            sum += b[i][j] * abs(x - j);
        while (x--)
        {
            res *= i;
        }
    }
    cout << sum << ' ' << res;
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

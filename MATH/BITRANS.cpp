#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxN = 1e3 + 1;   

ll n;
string f[maxN];

void ReadInput()
{
    f[1] = "0";
}

string Add(string a, string b)
{
    if (b.size() > a.size())
        swap(a, b);
    int i = a.size() - 1, j = b.size() - 1, save = 0;
    while (j >= 0)
    {
        int x = (a[i] - '0');
        int y = (b[j] - '0');
        int t = x + y + save;
        if (t > 9) save = 1;
        else save = 0;
        t %= 10;
        a[i] = t + '0';  
        i--;
        j--;
    }
    if (save == 1) 
    {
        for (; i >= 0; i--)
        {
            if (a[i] != '9')
            {
                a[i]++;
                break;
            }
            else
                a[i] = '0';
        }
        if (i == -1)
            a = "1" + a;
    }
    return a;
}

void Solve()
{
    string tmp = "0";
    for (int i = 2; i < maxN; i++)
    {
        if (i % 2 == 0) f[i] = Add(tmp, "1");
        else f[i] = tmp;
        tmp = Add(tmp, f[i]);
    }

    while (cin >> n)
    {
        cout << f[n] << '\n';
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



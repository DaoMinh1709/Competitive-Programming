#include <bits/stdc++.h>
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;
void Init()
{
    ll res = 1, cnt = 1, first = 0, second = 0;
    char c;
    while(cin >> c)
    {
        if (c != 'X')
            cnt++;
        else
        {
            first = cnt++;
            if (second == 0)
            {
                second = first;
                continue;
            }
            res *= (first - second);
            second = first;
        }
    }
    cout << res;
}

#define task "CHOCOLATE"
int main()
{
    faster
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    
    Init();
}

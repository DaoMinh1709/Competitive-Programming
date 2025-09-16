#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;   
const int MOD = 1e9 + 7;

int a, b, x, y;
string s, t;

void ReadInput()
{
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ':')
        {
            a = stoi(s.substr(0, i));
            b = stoi(s.substr(i + 1, s.size() - i - 1));
        }
    for (int i = 0; i < t.size(); i++)
        if (t[i] == ':')
        {
            x = stoi(t.substr(0, i));
            y = stoi(t.substr(i + 1, t.size() - i - 1));
        }
}

void Solve()
{
    if (x > b || y > a) cout << "NO";
    else cout << "YES";
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

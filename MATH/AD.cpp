#include <bits/stdc++.h>
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
using ll = long long;
const int maxN = 1e5 + 1;
string s1, s2;
int a[27], b[27];
void Init()
{
    fill(a, a + 27, 0);
    fill(b, b + 27, 0);
    cin >> s1 >> s2;
    for (char c : s1)
        a[c - 'a']++;
    for (char c : s2)
        b[c - 'a']++;
    ll res = 0;
    for (int i = 0; i <= 26; i++)
        res += abs(a[i] - b[i]);
    cout << res;
}

#define task "AD"
int main()
{
    faster
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    
    Init();
}

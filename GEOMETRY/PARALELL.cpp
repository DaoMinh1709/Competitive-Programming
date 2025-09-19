#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back

int const maxn = 1e4+7;
ll const INF = LLONG_MAX;

pair<int , int> p[maxn];
map<int , vector<int>> mp;
int n , k;

void input()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
            cin >> p[i].fi >> p[i].se;
    }
}

void solve()
{
    int X , Y;
    X = p[1].fi;
    Y = p[1].se;
    for(int i = 2 ; i <= n ; i++){
            int lx , ly , s;
            lx = X - p[i].fi;
            ly = Y - p[i].se;
            for(int j = 1 ; j <= n ; j++){
                    int Ratio = p[j].se * lx - p[j].fi * ly;
                    mp[Ratio].push_back(j);
                    s = mp.size();
                    if(s > k) break;
            }
            if(s == k){
                    bool flag = true;
                    for(auto u : mp){
                            if(u.se.size() == 1){
                                    flag = false;
                                    break;
                            }
                    }
                    if(flag){
                            for(auto u : mp){
                                    cout << u.se.size() << " ";
                                    for(auto v : u.se){
                                            cout << v << " ";
                                    }
                                    cout << "\n";
                            }
                            return;
                    }
            }
            mp.clear();
    }
}

int main()
{
   // freopen(".INP","r",stdin);
   // freopen(".OUT","w",stdout);
   // ios_base::sync_with_stdio(false);
   // cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        input();
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef tuple<ll,ll,ll> iii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

// #define w first
// #define s second
// #define v third

struct bloque {
    int w, s;
    ll v;
};

int n, maxw;
// w, s, v
vector<bloque> bloques;
// dp[i][j] es val maximo con peso j usando los primeros i
vector<vector<ll>> dp;

bool cmp(const bloque& a, const bloque& b) {
    return (a.w + a.s < b.w + b.s);
}

ll f(int i, int j) {
    if (i == n) return 0;
    if (dp[i][j] == -1) {
        ll ans = f(i+1,j);
        if (j <= bloques[i].s) {
            ans = max(ans, bloques[i].v + f(i+1,j+bloques[i].w));
        }
        dp[i][j] = ans;
    }
    return dp[i][j];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    maxw = 0;
    forn(i,n) {
        int w, s; ll v; cin>>w>>s>>v;
        maxw = max(maxw, w+s);
        bloques.push_back({w,s,v});
    }

    sort(bloques.begin(), bloques.end(), cmp);

    dp.assign(n+1, vector<ll>(maxw+1, -1));
    cout<<f(0,0)<<"\n";

    return 0;
}

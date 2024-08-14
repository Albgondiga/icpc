#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 1e4;
vector<ii> dp[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, q; cin>>n>>m>>q;

    while (m--) {
        int k, a, b; cin>>k>>a>>b;
        dp[b-a].pb({a,-1});
        dp[b-a].pb({a+k,-1});
    }

    forn(i,q) {
        int a, b; cin>>a>>b;
        if (a > b) swap(a,b);
        dp[b-a].pb({a,i});
    }

    vector<int> res(q);
    forn(i,n){
        sort(dp[i].begin(),dp[i].end());
        bool coso = false;
        for(auto [_,b] : dp[i]){
            if(b == -1) coso = !coso;
            else res[b] = coso;
        }
    }

    for(auto x : res) cout<<(x? "SI\n" : "NO\n");

    return 0;
}

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
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        ll n; cin>>n;
        vector<ll> v(n);
        for (ll& x : v) cin>>x;

        ll ans = 1e18;
        unordered_map<ll,ll> vis, oper;
        for (int i = 0; i < n; i++) {
            unordered_map<ll,bool> vis2;
            ll x = v[i], count = 0;
            while (!vis2[x]) {
                vis2[x] = true;

                vis[x] += 1;
                oper[x] += count;

                if (i == n-1 and vis[x] == n) ans = min(ans, oper[x]);

                if (x % 2) x += 1;
                else x /= 2;

                count++;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}

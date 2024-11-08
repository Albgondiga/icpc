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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<ll> a(n+1);
        for (ll i = 1; i <= n; i++) cin>>a[i];
        vector<pair<ll,ll>> lengths(n+1);
        for (ll i = 1; i <= n; i++) {
            lengths[i] = {a[i]+i-1, i};
        }
        sort(lengths.begin(), lengths.end());

        map<ll,bool> reachable;
        ll ans = n;
        for (ll i = 1; i <= n; i++) {
            if ((lengths[i].first == n) or 
                    (reachable.find(lengths[i].first) != reachable.end())) {
                ans = max(ans, lengths[i].first + lengths[i].second - 1);
                reachable[lengths[i].first + lengths[i].second - 1] = true;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}

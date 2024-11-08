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

    int t; cin>>t;
    while (t--) {
        int n, m; cin>>n>>m;
        vector<ll> a(n+1), b(m+1);
        for (int i = 1; i <= n; i++) cin>>a[i];
        for (int i = 1; i <= m; i++) cin>>b[i];

        int i = n, k = m;
        ll sum = 0, ans = 0;
        while (i >= 0 and k >= 0) {
            sum += a[i];
            if (sum > b[k]) {
                if (i < n) ans += (m-k);
                sum = a[i];
                k--;
            }
            i--;
        }
        if (i >= 0) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }


    return 0;
}

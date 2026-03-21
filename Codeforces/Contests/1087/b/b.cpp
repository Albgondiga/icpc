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

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        vector<ll> v(n);
        for (ll& x : v) cin>>x;

        forn(i,n) {
            int ans = 0;
            int m = 0, M = 0;
            for (int j = i+1; j < n; j++) {
                if (v[i] < v[j]) m++;
                else if (v[i] > v[j]) M++;       
            }
            cout<<max(m,M)<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

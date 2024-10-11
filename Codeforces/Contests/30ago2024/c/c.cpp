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
        int n; ll a, b; cin>>n>>a>>b;
        if (a < b) swap(a,b);
        ll arr[n];
        forn(i,n) cin>>arr[i];
        sort(arr, arr+n);
        ll median = arr[n/2];
        for (int i = 0; i < n/2; i++) {
            arr[i] += (arr[n/2]-arr[i])/a * a;
            arr[i] += (arr[n/2]-arr[i])/b * b;
        }
        for (int i = n/2+1; i < n; i++) {
            arr[i] -= (arr[i]-arr[n/2])/a * a;
            arr[i] -= (arr[i]-arr[n/2])/b * b;
        }
        cout<<arr[n-1]-arr[0]<<"\n";
    }
    return 0;
}

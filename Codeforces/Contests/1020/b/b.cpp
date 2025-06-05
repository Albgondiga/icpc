#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
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

    int t; cin>>t;
    while (t--) {
        int n, x; cin>>n>>x;
        for (int i = 0; i <= n-1; i++) {
            if (i == x) continue;
            cout<<i<<" ";
        }
        if (x <= n-1) cout<<x;
        cout<<"\n";
    }


    return 0;
}

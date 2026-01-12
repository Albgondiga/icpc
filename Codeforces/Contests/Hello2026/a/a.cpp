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

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        vector<int> v(n); 
        for (int& x : v) cin>>x;

        int l = -1, r = -1;
        forn(i,n) {
            if (v[i] == 0) {
                if (l == -1) l = i;
                r = i;
            }
        }
        
        if (l == -1 or l > 0 or r < n-1 or l == r) {
            cout<<"Alice\n";
        } else {
            cout<<"Bob\n";
        }
    }

    return 0;
}

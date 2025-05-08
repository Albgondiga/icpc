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
        int n; cin>>n;
        string a, b; cin>>a>>b;
        // Secuencia 1: arriba - abajo - arriba
        // Secuencia 2: abajo - arriba - abajo
        int ceros1 = 0, ceros2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') {
                if (i % 2 == 0) ceros1++;
                else ceros2++;
            }
            if (b[i] == '0') {
                if (i % 2 == 0) ceros2++;
                else ceros1++;
            }
        }
        if (ceros1 >= (n+1)/2 and ceros2 >= n/2) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}

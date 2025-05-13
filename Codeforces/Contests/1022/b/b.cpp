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
        ll n, x; cin>>n>>x;
        
        if (n == 1 and x == 0) {
            cout<<-1<<"\n";
            continue;
        }

        ll ans = 0;
        // Numero al que le voy a poner un 1
        ll num_actual = 1;
        for (int i = 32; i >= 1; i--) {
            if ((1LL << i) & x) {
                // Si hay un 1 le pongo uno al numero
                ans += (1LL << i);
                if (num_actual < n) num_actual++;
            }
        }
        // Relleno los numeros nulos
        ll diff = n - num_actual + 1;
        if (1LL & x == 0) {
            if (diff % 2 == 0) {
                ans += diff;
            } else {
                if (diff+1 <= n) {
                    ans += diff+1;
                } else {
                    ans += diff;
                    ans += 4;
                }
            }
        } else { // Hay un 1 al final
            if (diff % 2 == 1) {
                ans += diff;
            } else {
                if (diff+1 <= n) {
                    ans += diff+1;
                } else {
                    ans += diff;
                    ans += 4;
                }
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}

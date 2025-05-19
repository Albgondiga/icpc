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
  
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

int calc_msb(int x) {
    for (int j = 30; j >= 0; j--) {
        if (x & (1 << j)) {
            return j;
        }
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        int n, q; cin>>n>>q;
        vector<int> w(n);
        for (int& x : w) cin>>x;

        int prefix_msb[n][31];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 30; j++) {
                prefix_msb[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            int msb = calc_msb(w[i]);
            for (int j = 0; j <= 30; j++) {
                if (msb >= j) prefix_msb[i][j] = i;
                else prefix_msb[i][j] = (i == 0 ? -1 : prefix_msb[i-1][j]);
            }
        }

        vector<int> prefix_xor(n);
        prefix_xor[0] = w[0];
        for (int i = 1; i < n; i++) 
            prefix_xor[i] = w[i]^prefix_xor[i-1];

        while (q--) {
            int x; cin>>x;
            int score = 0;
            ifd cout<<"x = "<<x<<endl;
            int i = n-1;
            while (i >= 0 and x > 0) {
                // Busco el primero con msb mayor o igual a mi y me como
                // a todos esos
                int msb = calc_msb(x);
                int siguiente = prefix_msb[i][msb];
                
                if (siguiente == i) {
                    i--;
                    continue;
                }

                ifd cout<<"i = "<<i<<", msb = "<<msb<<", siguiente = "<<siguiente<<endl;
                x ^= (prefix_xor[i] ^ prefix_xor[(siguiente == -1 ? 0 : siguiente)]);
                
                score += (i-siguiente-1);
                // Me voy a donde estaba el mayor o igual a mi
                i = siguiente;
                if (i == -1) break;
                if (w[i] > x) break;
                score++;
                i--;
            }

            cout<<score<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

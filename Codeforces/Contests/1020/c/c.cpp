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
        int n; ll k; cin>>n>>k;
        vector<ll> a(n), b(n);
        for (ll& x : a) cin>>x;

        ll objetivo = -1;
        bool seguir = true;
        for (int i = 0; i < n; i++) {
            cin>>b[i];
            if (b[i] != -1) {
                if (objetivo == -1) {
                    objetivo = a[i]+b[i];
                } else if (objetivo != a[i]+b[i]) {
                    seguir = false;
                }
            }
        }
        if (seguir) {
            if (objetivo == -1) {
                ll m = (*min_element(a.begin(),a.end()));
                ll M = (*max_element(a.begin(),a.end()));
                cout<<m+k-M+1<<"\n";
            } else {
                seguir = true;
                for (int i = 0; i < n; i++) {
                    if (b[i] == -1) {
                        if (objetivo-a[i] > k or objetivo < a[i]) {
                            seguir = false;
                            break;
                        }
                    } else if (objetivo != a[i]+b[i]) {
                        seguir = false;
                        break;
                    }
                }
                cout<<(seguir ? 1 : 0)<<"\n";
            }
        } else {
            cout<<0<<"\n";
        }
    }

    return 0;
}

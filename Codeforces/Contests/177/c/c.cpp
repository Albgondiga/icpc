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
    while(t--) {
        int n; cin>>n;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++) {
            cin>>v[i];
        }

        set<int> malPuestos;
        for (int i = 1; i <= n; i++) {
            int d; cin>>d;
            int x = v[d];
            while (true) {
                if (malPuestos.find(x) != malPuestos.end()) break;
                malPuestos.insert(x);
                x = v[x];
            }
            cout<<malPuestos.size()<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

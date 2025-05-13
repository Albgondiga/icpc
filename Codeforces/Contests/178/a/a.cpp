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
        int a, b, c; cin>>a>>b>>c;
        int total = a+b+c;
        if (total % 3) {
            cout<<"NO\n";
            continue;
        }
        int tamano = total/3;
        if (tamano < a or tamano < b) {
            cout<<"NO\n";
            continue;
        }
        int necesito = tamano-a+tamano-b;
        if (c == tamano+necesito) {
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }

    return 0;
}

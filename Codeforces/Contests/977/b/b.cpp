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
        int n; ll x; cin>>n>>x;
        set<ll> seen;
        vector<ll> candidatos, repetidos;

        forn(i,n) {
            ll a; cin>>a;
            if (seen.find(a) != seen.end()) repetidos.push_back(a);
            else seen.insert(a);
        }
        forn(i,n+1) {
            if (seen.find(i) == seen.end()) candidatos.push_back(i);
        }

        map<ll,vector<int>> modulos;
        sort(repetidos.begin(), repetidos.end(), greater<int>());
        for (ll& a : repetidos) {
            modulos[a%x].push_back(a);
        }
        ll ans = 0;
        for (ll& a : candidatos) {
            if (modulos[a%x].empty()) {
                ans = a;
                break;
            }
            ll posible = modulos[a%x][modulos[a%x].size()-1];
            if (posible > a) {
                ans = a;
                break;
            } else {
                modulos[a%x].pop_back();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

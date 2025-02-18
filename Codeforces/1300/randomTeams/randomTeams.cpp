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
const int MAXN=100100;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, m; cin>>n>>m;
    ll kmin = 0, kmax = 0;

    if (n != 1) {
        // Min
        ll base = n/m;
        ll mod = n%m;
        ll equiposMas = (base+1)*(base)/2;
        ll equiposMenos = (base)*(base-1)/2;
        ifd {
            cout<<"base = "<<base<<endl;
            cout<<"mod = "<<mod<<endl;
            cout<<"equiposMas = "<<equiposMas<<endl;
            cout<<"equiposMenos = "<<equiposMenos<<endl;
        }
        kmin = (mod*equiposMas + (m-mod)*equiposMenos); 
        // Max
        kmax = (n-m+1)*(n-m)/2;
    }

    cout<<kmin<<" "<<kmax<<"\n";

    return 0;
}
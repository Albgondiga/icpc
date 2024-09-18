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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 2e5+1;
const int LOG = 30;
int n, q;
int up[N][LOG+1];

int kthAncestor(int v, int k) {
    for (int l = LOG; l >= 0; l--) {
        if (k >= (1 << l)) {
            v = up[v][l];
            k -= (1 << l);
        }
    }
    return v;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>q;
    for (int v = 1; v <= n; v++) {
        cin>>up[v][0];
    }

    // Binary lifting sin preprocess
    for (int l = 1; l <= LOG; l++) {
        for (int v = 1; v <= n; v++) {
            up[v][l] = up[up[v][l-1]][l-1];
        }
    }

    while(q--) {
        int a, b; cin>>a>>b;
        for (int k = 1; k <= LOG; k++) {
            if ()
        }
        cout<<kthAncestor(x,k)<<"\n";
    }

    return 0;
}

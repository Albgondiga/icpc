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

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, m; cin>>n>>m;
    vector<ll> v(n+1);
    forn(i,n) cin>>v[i+1];

    // Vector de posisiones
    vector<int> index(n+1);
    forn(i,n) index[v[i+1]] = i+1;
    // Rondas inciales
    ll count = 1;
    for (ll i = 1; i < n; i++) {
        if (index[i+1] < index[i]) {
            count++;
        }
    }

    set<pll> swaps;

    forn(k,m) {
        ll a,b; cin>>a>>b;

        // Revisar consecutivos
        if (v[a]+1 <= n)
            swaps.insert( {v[a],v[a]+1} );
        if (v[a]-1 >= 1)
            swaps.insert( {v[a]-1,v[a]} );
    
        if (v[b]+1 <= n)
            swaps.insert( {v[b],v[b]+1} );
        if (v[b]-1 >= 1)
            swaps.insert( {v[b]-1,v[b]} );

        for (auto swapped : swaps) {
            if (index[swapped.first] > index[swapped.second]) {
                count--;  // Si estaba despues, ahora va antes
            }
        }
    
        swap(v[a], v[b]);
        index[v[a]] = a;
        index[v[b]] = b;

        for (auto swapped : swaps) {
            if (index[swapped.first] > index[swapped.second]) {
                count++;
            }
        }

        cout<<count<<"\n";
        swaps.clear();
    }

    return 0;
}
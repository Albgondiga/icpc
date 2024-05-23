#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, k, q; cin>>n>>k>>q;
    vector<ll> sums(200002, 0);
    forn(i,n) {
        ll l,r; cin>>l>>r;
        sums[l] += 1;
        // Si intervalo termina justo antes que mi,
        // entonces no me incluye
        sums[r+1] -= 1; // No duplicar intervalos
    }
    // Cuantas recetas incluyen a i
    for (int i = 1; i <= 200000; i++) {
        sums[i] += sums[i-1];
    }
    // Receta valida o no
    for (int i = 1; i <= 200000; i++) {
        if (sums[i] >= k) 
            sums[i] = 1;
        else
            sums[i] = 0;
    }
    // Recetas validas menores o iguales a i
    for (int i = 1; i <= 200000; i++) {
        sums[i] += sums[i-1];
    }
    forn(i,q) {
        ll count = 0;
        ll a,b; cin>>a>>b;
        cout<<sums[b]-sums[a-1]<<"\n";
    }
    return 0;
}
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

#define debug 1
#define ifd if (debug)

ll Bloque(ll x, ll y, ll si, ll se) {
    if (x == 1) // Interno
        return (y-1)/si;  // Bloque dado por parte entera de division
    return  (y-1)/se; // Externo
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n,m,q; cin>>n>>m>>q;

    ll mcd = __gcd(n,m);
    ll si = n/mcd;  // Secciones internas
    ll se = m/mcd;  // Secciones externas

    // Bloques separados por muros dobles
    // Puedo ir de una seccion a otra solo si estan
    // en el mismo bloque

    forn(i,q) {
        ll sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        if (Bloque(sx,sy,si,se) == Bloque(ex,ey,si,se)) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}
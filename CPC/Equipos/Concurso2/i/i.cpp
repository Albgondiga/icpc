// 
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
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, m; cin>>n>>m;
    ll suma = 0;
    map<ll,ll> mapa;
    set<ll> val;
    forn(i,n) {
        ll a; cin>>a;
        suma += a;
        val.insert(a);
        mapa[a]++;
    } 

    ll maxSuma = suma;
    while(m--) {
        ll b, c; cin>>b>>c;
        if (debug) cout<<"puedo cambiar "<<b<<" maes a "<<c<<endl;
        while(b) {
            auto it = val.begin();
            
            if (debug) cout<<"vea que el mae más chiquito ahorita es "<<*it<<", y puedo cambiar "<<b<<endl;


            if (*it >= c) {
                b = 0;
            } else {
                if (debug) cout<<"vea que tengo "<<mapa[*it]<<" maes de "<<*it<<endl;
                if (b < mapa[*it]) {
                    suma -= b * (*it);
                    suma += b*c;
                    val.insert(c);
                    mapa[c] += b;

                    mapa[*it] -= b;
                    b = 0;
                } else {
                    suma -= mapa[*it] * (*it);
                    suma += mapa[*it]*c;
                    val.insert(c);
                    mapa[c] += mapa[*it];

                    b -= mapa[*it];
                    mapa[*it] = 0;
                    // mapa.erase(*it);
                    val.erase(*it);
                }
                if (debug) cout<<"de donde mi suma ahorita es "<<suma<<endl;
            }
        }
        if (debug) cout<<"suma="<<suma<<endl;
        maxSuma = max(suma, maxSuma);
    }
    
    cout<<suma<<"\n";

    return 0;
}

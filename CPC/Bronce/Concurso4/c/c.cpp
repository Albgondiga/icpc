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
typedef pair<ll,ll> pll;
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll N, P; cin>>N>>P;

    // Misma idea pero se hacia rapido con este
    // mapa (contar exponente de cada factor primo)
    // y repartirlo
    map<ll,ll> count;

    for (ll d = 2; d*d <= P; d++) {
        while (P % d == 0) {
            P /= d;
            count[d]++;
        }
    }

    if(P > 1) count[P]++;

    // No hacia falta binpow
    ll mcd = 1;
    for(auto i:count) {
        ll exp = i.second/N;
        forn(k,exp)
            mcd *= i.first;
    }

    cout<<mcd<<endl;
    return 0;
}
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
typedef pair<ll, ll> ii;
#define iii pair<ii, ll>

#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;
#define plazo first.first
#define skip first.second
#define precio second
#define debug 1
#define ifd if (debug&&i<=5)
const ll END=1e6;
ll n, k;
vector<ii> v;

// usted busca el index del último mae <x
ll search(ll x) {
    ll a =0, b=n-1;
    ll c;
    while (a<=b) {
        c=a+(b-a)/2;
        if (v[c].first<=x) a=c+1;
        else b=c-1;
    }

    return a-1;
}



int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    v.resize(n);
    forn(i,n) cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
    

    ll minPrecio=1e9+7;
    vector<iii> tickets(k);
    forn(i, k) {
        cin>>tickets[i].plazo>>tickets[i].skip>>tickets[i].precio;
        if(tickets[i].skip) minPrecio=min(minPrecio, tickets[i].precio);
    }
    vector<ll> solve(n+1);
    solve[n]=0;
    for(ll i=n-1; i>=0; i--) {
        if (i==n-1) {
            solve[i]=min(v[i].second,minPrecio);
            continue;
        }

        solve[i]=v[i].second+solve[i+1];

        for(iii t:tickets) {
            ll cPlazo=t.plazo, cSkips=t.skip, cPrecio=t.precio;
            // el último que skippearía given sus skips
            ll lSkip=min(i+cSkips-1, n-1);
            // el último que skippearía given su plazo
            ll lPlazo = search(v[i].first+cPlazo-1);
            ll nxt=min(lSkip, lPlazo) +1;

            solve[i]=min(solve[i], cPrecio+solve[nxt]);
        }
    }


    cout<<solve[0]<<endl;
    




}
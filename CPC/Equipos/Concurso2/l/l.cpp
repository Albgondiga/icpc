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

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // Nos falto tomar en cuenta los numeros a la izquierda 
    // de las potencias de 100 (n2-n <= x <= n2-n+1) y los casos x = n2-2n
    // ( desde 100 se veía el patrón :( )
    // Precomputar los intervalos
    vector<pll> intervals;
    ll n = 1, n2 = 1;
    intervals.push_back({n,n2});
    for (ll i = 1; i <= 9; i++) {
        n *= 10;
        n2 *= 100;
        intervals.push_back({n2-2*n,n2-2*n});
        intervals.push_back({n2-n,n2+n-1});
    }

    int t; cin>>t;
    while(t--) {
        ll x; cin>>x;
        ll count = 0;
        for (auto i : intervals) {
            ll start = i.first;
            ll end = min(i.second, x);
            if (start <= end) count += (end-start+1);
        }
        cout<<count<<"\n";
    }
}

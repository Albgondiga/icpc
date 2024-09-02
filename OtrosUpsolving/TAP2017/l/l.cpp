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

#define debug 1
#define ifd if (debug)

const ll INF = 1e18;

ll tomar2(ll& fig1, ll& fig2) {
    ll x = min(fig1/2, fig2/2);
    fig1 -= 2LL*x;
    fig2 -= 2LL*x;
    return x;
}

ll tomar4(ll& fig) {
    ll x = fig/4;
    fig -= 4LL*x;
    return x;
}

ll casoRaro(ll& fig1, ll& fig2, ll& fig3) {
    ll x = min(fig1, min(fig2, fig3/2));
    fig1 -= x;
    fig2 -= x;
    fig3 -= 2LL*x;
    return x;
}

ll comb(ll l, ll o, ll s, ll t) {
    if (l < 0 || o < 0 || s < 0 || t < 0) return -1LL*INF;
    ll count = 0;
    count += tomar2(l, s);
    count += tomar4(l);
    count += tomar4(o);
    count += tomar4(t);
    return count;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll l, o, s, t; cin>>l>>o>>s>>t;
    ll count = 0; 
    // LLOO: 0 LSTT: 0 
    count = max(count, comb(l,o,s,t));
    // LLOO: 1 LSTT: 0 
    count = max(count, comb(l-2,o-2,s,t)+1);
    // LLOO: 0 LSTT: 1 
    count = max(count, comb(l-1,o,s-1,t-2)+1);
    // LLOO: 1 LSTT: 1
    count = max(count, comb(l-3,o-2,s-1,t-2)+2);

    cout<<count<<"\n";

    return 0;
}

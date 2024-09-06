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

#define debug 1
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    vector<ll> wish(n), have(n);
    forn(i, n) cin>>wish[i];
    forn(i,n) cin>>have[i];
    sort(wish.begin(), wish.end());
    sort(have.begin(), have.end());
    vector<ll> gana(n);
    forn(i, n) 
        gana[i] =(upper_bound(wish.begin(), wish.end(), have[i])-wish.begin());
    const ll MOD =1e9+7;
    ll res=1;
    ll taken=0;
    forn(i,n ) {
        res=(res*(gana[i]-taken))%MOD;
        if (res==0) break;
        taken++;
    }
    cout<<res<<"\n";

}

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

// Direccions para der, izq, arriba, abajo
ll dx[4] = { 0, 0, -1, 1 };
ll dy[4] = { 1, -1, 0, 0 };

bool isValid(ll x, ll y, ll n, ll m) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

ll countAdj(ll x, ll y, ll n, ll m) {
    ll count = 0;
    forn(i,4) {
        if (isValid(x+dx[i],y+dy[i],n,m))
            count++;
    }
    return count;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t; cin>>t;
    forn(i,t) {
        ll n, m; cin>>n>>m;
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<min(countAdj(x1,y1,n,m),countAdj(x2,y2,n,m))<<"\n";
    } 
    return 0;
}
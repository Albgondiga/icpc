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
const int sz=10000007;
// const int sz =100;

#define debug 0
#define ifd if (debug)

struct UF {
    vector<int> link, size;

    UF(int n) {
        link.resize(n);
        size.resize(n);
        forn(i,n) link[i] = i;
        forn(i,n) size[i] = 1;
    }

    int find(int x) {
        while (x != link[x]) x = link[x];
        return x;
    }

    bool same(int a, int b) {
        return (find(a) == find(b));
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return 0;
        if (size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        link[b] = a;
        return 1;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m; cin>>n>>m;

    map<ll,ll> id;
    vector<ll> v;
    ll maxV = 1;
    for (ll i = 1; i <= n; i++) {
        ll x; cin>>x;
        maxV = max(maxV,x);
        id[i] = x;
    }

    UF uf(n+1);
    vector<ll> adj[sz];
    forn(i,m) {
        ll a, b; cin>>a>>b;        
        ll aa = min(id[a], id[b]), bb = max(id[a], id[b]);
        adj[bb].push_back(aa);
    }

    ll ans = 1;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ifd cout<<"estoy en "<<i<<endl;
        cnt++;
        for (auto u:adj[i]) {
            ifd cout<<"vea que tiene a "<<u<<" adyacente"<<endl;
            cnt -= uf.unite(i, u);

        }
        if (cnt == 1) ans = i;
        ifd cout<<"cnt = "<<cnt<<endl;
    }
    cout<<ans<<endl;
        
    return 0;
}

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

#define debug 1
#define ifd if (debug)

vector<int> componente1;
vector<bool> visited[sz];

void dfs(int ) {

}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;

    map<ll,ll> id;
    vector<ll> v;
    for (ll i=1; i<=n; i++) {
        ll x; cin>>x;
        // if (x>n) continue;
        id[i]=x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll k = 1;
    for (ll i=1; i<n; i++) {
        if (v[i]!=(v[i-1]+1)) break;
        k=v[i];
    }
    // ifd cout<<"k = "<<k<<endl;
    vector<ll> adj[sz];

    forn(i,m ) {
        ll a, b; cin>>a>>b;
        adj[id[a]].push_back(id[b]);
        adj[id[b]].push_back(id[a]);
    }
    bitset<sz> seen;

    seen[1]=true;
    queue<ll> q;
    q.push(1);
    while (!q.empty()) {
        ll x = q.front(); q.pop();
        for (auto u:adj[x]) {
            if (seen[u]||u>k) continue;
            seen[u]=true;
            q.push(u);
        }
    }
    ll maxR=1;
    for (ll i=1; i<=k; i++) {
        if (!seen[i]) break;
        maxR=i;
    }
    cout<<maxR<<endl;

    return 0;
}

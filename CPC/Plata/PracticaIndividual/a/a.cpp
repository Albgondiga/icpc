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

const int N = 100+5;
vector<int> adj[N];
bool visited[N];

void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto m : adj[n]) {
        dfs(m);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    int a, b;
    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll count = 0;
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    cout<<count<<"\n";

    return 0;
}
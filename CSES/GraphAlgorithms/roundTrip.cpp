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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 1e5+1;
int n, m;
bool visited[N];
vector<int> parent;
vector<int> adj[N];
int first, last;

bool dfs(int v, int par) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (u == par) continue;
        if (visited[u]) {
            last = v; first = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    visited[v] = 2;
    return false;
}

void findCycle() {
    parent.assign(N,-1);
    first = -1;

    for (int v = 1; v <= n; v++) {
        if (!visited[v] and dfs(v, parent[v])) break;
    }

    if (first == -1) {
        cout<<"IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(first);
        for (int v = last; v != first; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(first);
        reverse(cycle.begin(), cycle.end());

        cout<<cycle.size()<<"\n";
        for (auto v : cycle) cout<<v<<" ";
        cout<<"\n";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(i,m) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findCycle();

    return 0;
}

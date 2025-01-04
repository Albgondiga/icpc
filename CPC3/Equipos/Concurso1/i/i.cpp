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

#define debug 0
#define ifd if (debug)

const int N = 1e5+5;
const int LOG = 20;

int n, q, timer, nodeCount; 

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> tin, tout, nodeCountV;
vector<int> subtree;

void dfs(int v, int p) {
    tin[v] = ++timer;
    nodeCountV[v] = nodeCount++;

    up[v][0] = p;
    for (int i = 1; i <= LOG; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    subtree[v] = 1;
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
        subtree[v] += subtree[u];
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v]) && (tout[u] >= tout[v]);
}

int maxWaterUp(int v, int water) {
    for (int i = LOG; i >= 0; i--) {
        if (subtree[up[v][i]] < water)
            v = up[v][i];
    }
    return v;
}

void preprocess(int root) {
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    nodeCountV.assign(n+1,0);
    subtree.assign(n+1,0);
    timer = 0;
    nodeCount = 0;
    up.assign(n+1, vector<int>(LOG));
    dfs(root, root);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        cin>>n>>q;

        adj.assign(n+1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int p; cin >> p;
            adj[p].push_back(i);
        }

        preprocess(1);

        while (q--) {
            int v, water, u; cin>>v>>water>>u;

            if (is_ancestor(v,u)) {  // v arriba de u
                if (water >= subtree[v]) {
                    cout<<"YES\n";
                } else {
                    if (nodeCountV[u]-nodeCountV[v]+1 <= water) {
                        cout<<"YES\n";
                    } else {
                        cout<<"NO\n";
                    } 
                }
            } else {  // u arriba o igual que v
                int s = maxWaterUp(v, water);
                if (is_ancestor(s,u)) {
                    // Si puedo llegar incluso arriba de u si
                    cout<<"YES\n";
                } else {  // Si no puedo llegar arriba de u
                    int p = up[s][0];
                    if (is_ancestor(p,u)) { // p tiene que estar encima de u
                        if (tin[u] < tin[s]) water -= subtree[s];
                        if (nodeCountV[u]-nodeCountV[p]+1 <= water) {
                            cout<<"YES\n";
                        } else {
                            cout<<"NO\n";
                        }
                    } else {
                        cout<<"NO\n";
                    }
                }
            }
        }
    }

    return 0;
}

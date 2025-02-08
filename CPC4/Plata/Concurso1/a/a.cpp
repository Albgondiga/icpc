#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

int n, m, s;
const int N = 2e4+5;

int link[N], sizes[N];
vector<pair<int, int>> adj[N];
vector<int> tin(N), tout(N), up[N][20];

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a, b);
    sizes[a] += sizes[b];
    link[b] = a;
}

void kruskal(const vector<tuple<int, int, int>>& edges) {
    for (int i = 1; i <= n; i++) {
        link[i] = i;
        sizes[i] = 1;
    }

    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        int w, a, b; tie(w, a, b) = e;
        w *= -1;
        if (!same(a, b)) {
            unite(a, b);
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
    }
}

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin>>n>>m>>s) {
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; i++) {
            int a, b, w; cin>>a>>b>>w;
            edges.push_back({-w, a, b});
        }

        kruskal(edges);


    }

    return 0;
}

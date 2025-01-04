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

const int INF = 1e9;
const int N = 1e4;
int n;
int adj[N][N];
ii nodos[N];

struct Edge {
    int w = INF, to = -1;
};

int prim() {
    int totalWeight = 0;
    bool selected[n] = {0};
    Edge minEdge[n];
    minEdge[0].w = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!selected[j] and (v == -1 or minEdge[j].w < minEdge[v].w)) {
                v = j;
            }
        }

        if (minEdge[v].w == INF) {
            return -1;
        }

        selected[v] = true;
        totalWeight += minEdge[v].w;

        for (int to = 0; to < n; to++) {
            if (adj[v][to] < minEdge[to].w) {
                minEdge[to] = {adj[v][to], v};
            }
        }
    }

    return totalWeight;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int x, y; 
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        nodos[i] = {x,y};
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ii n1 = nodos[i], n2 = nodos[j];
            int dist = abs(n1.first-n2.first) + abs(n1.second-n2.second);
            adj[i][j] = adj[j][i] = dist;
        }
    }

    cout<<2*prim()<<"\n";

    return 0;
}

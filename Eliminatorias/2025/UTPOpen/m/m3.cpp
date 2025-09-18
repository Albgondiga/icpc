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

const int N = 1e4+1;
int n, m; 

struct dsu {
    vector<int> link, r;
    ll costo = 0;
    int aristas = 0;

    dsu() : link(N), r(N, 0) {
        for (int i = 0; i < N; ++i) link[i] = i;
    }
};


vector<dsu> arboles(1); 
vector<tuple<ll,int,int>> edges;

int find(int a, int arbol) {
    if ((arboles[arbol].link)[a] != a) {
        (arboles[arbol].link)[a] = find((arboles[arbol].link)[a], arbol);
    }
    return (arboles[arbol].link)[a];
}

bool same(int a, int b, int arbol) {
    return find(a,arbol) == find(b,arbol);
}

void unite(int a, int b, int arbol) {
    a = find(a, arbol), b = find(b, arbol);
    if ((arboles[arbol].r)[a] == (arboles[arbol].r)[b]) {
        (arboles[arbol].r)[a]++;
    }
    if ((arboles[arbol].r)[a] > (arboles[arbol].r)[b]) {
        (arboles[arbol].link)[b] = (arboles[arbol].link)[a];
    } else {
        (arboles[arbol].link)[a] = (arboles[arbol].link)[b];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b; ll w; 
        cin>>a>>b>>w;
        edges.push_back({w,a,b});
    }
    sort(edges.begin(), edges.end());
    
    for (auto& e : edges) {
        int a, b; ll w;
        tie(w,a,b) = e;
        
        int arbol = -1;
        for (int i = 0; i < arboles.size(); i++) {
            if (!same(a,b,i)) {
                arbol = i;
                break;
            }
        }
        if (arbol == -1) {
            arboles.push_back(dsu());
            arbol = arboles.size()-1;
        }
        arboles[arbol].costo += w;
        arboles[arbol].aristas++;
        unite(a, b, arbol);
    }

    vector<ll> ans;
    for (auto& arbol : arboles) {
        if (arbol.aristas == n-1) ans.push_back(arbol.costo);
    }

    cout<<ans.size()<<"\n";
    int i = 0;
    for (ll& costo : ans) cout<<costo<<"\n";
    
    return 0;
}

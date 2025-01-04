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

#define debug 0
#define ifd if (debug)

const int N = 1e4+1;
int n;

map<int,ii> nodos;
pair<ll, ii> edges[N*(N-1)];
int link[N];
int sizes[N];

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    link[b] = a;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i = 1; i <= n; i++) {
        int x, y; cin>>x>>y;
        nodos[i] = {x,y};
    }

    for (int i = 1; i<=n; i++) link[i] = i;
    for (int i = 1; i<=n; i++) sizes[i] = 1;

    stack<pair<int, ii>> v[4001];
    for(int i = 1; i <= n; i++) {
        ii n1 = nodos[i]; 
        for(int j = i+1; j <= n; j++) {
            ii n2 = nodos[j];
            int dist = abs(n1.first-n2.first)+abs(n1.second-n2.second);
            v[dist].push({dist, {i, j}});
            v[dist].push({dist, {j, i}});
            // edges.push_back({dist, {i, j}});
            // edges.push_back({dist, {j, i}});
        }
    }

    int cost = 0, contador = 0;
    for (int i = 1; i <= 4000; i++) {
        while (!v[i].empty()) {
            edges[contador++] = (v[i].top());
            v[i].pop();
        }
    }
    //sort(edges.begin(), edges.end());
    for (int i = 0; i < contador; i++) {
        auto e = edges[i];
        int n1 = e.second.first, n2 = e.second.second;
        if (!same(n1,n2)) {
            ifd cout<<"Voy de "<<nodos[n1].first<<","<<nodos[n1].second
                <<" a "<<nodos[n2].first<<","<<nodos[n2].second<<endl;
            cost += e.first;
            unite(n1,n2);
        }
    }
    cout<<cost*2<<"\n";
    return 0;
}

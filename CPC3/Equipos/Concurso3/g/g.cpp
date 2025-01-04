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
vector<int> link, size;

int find(int x) {
    while(x!=link[x]) x= link[x];
    return x;
}

struct UF {
    vector<int> link, size;
    UF(int n) {
        link.resize(n);
        size.resize(n);
        forr(i,1, n+1) link[i] = i;
        forr(i, 1, n+1) size[i]=1;
    }

    int find(int x) {
        while(x!=link[x]) x= link[x];
        return x;
    }

    bool same(int a, int b ) {
        return find(a)==find(b);
    }

    void unite(int a, int b) {
        a=find(a);
        b=find(b);
        if (size[a]<size[b]) swap(a, b);
        size[a]+=size[b];
        link[b] = a;
    }
};

vector<int> distA, distB;
vector<vector<int> > adyacencia;
vector<bool> seenA, seenB;
void dfsA(int a) {
    seenA[a]=true;
    ifd cout<<"llamo dfsA sobre a = "<<a<<endl;
    for (auto u:adyacencia[a]) {
        if (seenA[u]) continue;
        distA[u]=distA[a]+1;
        dfsA(u); 
    }
}

void dfsB(int b) {
    seenB[b]=true;
    for (auto u:adyacencia[b]) {
        if (seenB[u]) continue;
        distB[u]=distB[b]+1;
        dfsB(u); 
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    UF uF(n);
    vector<pair<ll, ii> > adj(m);
    forn(i, m) {
        int a, b; ll x;
        cin>>a>>b>>x;
        a--; b--;
        adj[i] = {x, {a, b}};
        // if (!uF.same(a, b)) {
        //     ifd cout<<a<<" y "<<b<<" están en el mismo ahora"<<endl;
        //     uF.unite(a, b);
        // }
    }

    sort(adj.begin(), adj.end());

    ll cost=0;
    stack<ii> aristas;
    forn(i, m) {
        int a = adj[i].second.first, b = adj[i].second.second;
        if (!uF.same(a, b)) {
            uF.unite(a, b);
            aristas.push({a, b});
            cost+=adj[i].first;
        }
    }
    
    cout<<cost<<endl;
    adyacencia.resize(n);
    while(!aristas.empty()) {
        ii current=aristas.top();
        aristas.pop();
        adyacencia[current.first].push_back(current.second);
        adyacencia[current.second].push_back(current.first);
    }

    seenA.resize(n); seenB.resize(n);
    distA.resize(n); distB.resize(n);
    distA[0]=0;
    dfsA(0);
    int b=0;
    forn(i, n) if (distA[i]>distA[b]) b=i;
    if (debug) cout<<"b = "<<b<<endl; 
    distB[b]=0;
    dfsB(b);
    int c = 0;
    forn(i, n) if (distB[i]>distB[c]) c=i;
    

    cout<<distB[c]<<endl;
    // cout<<maxCosto<<endl;



}

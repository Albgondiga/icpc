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

const ll INF = 1e18;
const int N = 1e4+5;
pair<string, vector<ll>> prot[N];
//vector<int> adj[N];
vector<int> ans;
bool selected[N];
int n, l, k;

struct Edge {
    ll w = 0, to = -1;
};

// O(n^2)
void prim() {
    vector<ll> minDist(n);
    // Calculo las distancias hasta el nodo 0
    for (int i = 0; i < n; i++) {
        ll dist = 0;
        for (int j = 0; j < l; j++) dist += abs(prot[i].second[j] - prot[0].second[j]);
        minDist[i] = dist;
    }
    // Busco el elemento con la mayor distancia
    int primero = max_element(minDist.begin(), minDist.end()) - minDist.begin();
    selected[primero] = true;
    ans.push_back(primero);
    // Calculo las distancias hasta el primero
    for (int i = 0; i < n; i++) {
        if (i == primero) continue;
        ll dist = 0;
        for (int j = 0; j < l; j++) dist += abs(prot[i].second[j] - prot[primero].second[j]);
        minDist[i] = dist;
    }
    // Prim
    for (int i = 0; i < k-1; i++) {
        // Escojo el siguiente que se une al arbol
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!selected[j] and (v == -1 or minDist[j] > minDist[v]))
                v = j;
        }
        selected[v] = true;
        ans.push_back(v);
        // Actualizo maximos
        for (int j = 0; j < n; j++) {
            if (selected[j]) continue;
            ll dist = 0;
            for (int x = 0; x < l; x++) dist += abs(prot[j].second[x] - prot[v].second[x]);
            minDist[j] = min(minDist[j], dist);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>l>>k;
    for (int i = 0; i < n; i++) {
        cin>>prot[i].first;
        (prot[i].second).resize(l);
        for(ll& x : prot[i].second) cin>>x;
    }

    prim();
    for (int& i : ans) {
        cout<<prot[i].first<<"\n";
    }

    return 0;
}

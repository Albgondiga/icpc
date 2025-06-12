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

// https://codeforces.com/gym/103960/problem/L

const int N = 1e5+5;

int n;
int timer = 0;
map<pair<int,int>,int> idx;
vector<int> colorNodo(N), colorFreq(N), ans(N);
vector<int> adj[N];
bool visited[N];
vector<map<int,ll>> freq(N);

void dfs(int v, int p) {
    if (visited[v]) return;

    visited[v] = true;
    (freq[v])[colorNodo[v]]++;

    for (int u : adj[v]) {
        if (visited[u]) continue;
        dfs(u,v);
        if (freq[u].size() > freq[v].size()) swap(freq[u], freq[v]);
        for (auto& x : freq[u]) {
            (freq[v])[x.first] += x.second;
        }
    }

    if (v == 1) return;
    ll count = 0;
    for (auto& x : freq[v]) {
        ll abajo = x.second, arriba = colorFreq[x.first]-abajo;
        count += (abajo*arriba);
    }
    ans[idx[{min(v,p),max(v,p)}]] = count;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>colorNodo[i];
        colorFreq[colorNodo[i]]++;
    }
    for (int i = 1; i <= n-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u > v) swap(u,v);
        idx[{u,v}] = i;
    }

    dfs(1,1);

    for (int i = 1; i <= n-1; i++) cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}

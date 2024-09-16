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

// https://www.geeksforgeeks.org/cses-solutions-cycle-finding/

const ll INF = 1e18;
const int N = 2501;
int n, m;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    vector<tuple<int,int,ll>> edges;
    forn(i,m) {
        int a, b; ll w;
        cin>>a>>b>>w;
        edges.push_back({a,b,w});
    }
    // Bellman Ford
    ll dist[N];
    int previous[N] = {0};
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b; ll w;
            tie(a,b,w) = e;
            if (dist[a]+w < dist[b]) {
                previous[b] = a;
                dist[b] = dist[a]+w;
            } 
        }
    }
    for (auto e : edges) {
        int a, b; ll w;
        tie(a,b,w) = e;
        if (dist[a]+w < dist[b]) {
            previous[b] = a;
            // Buscar ciclo
            stack<int> cycle;
            // Iterar suficientes veces para entrar en el ciclo
            for (int i = 1; i <= n; i++) {
                b = previous[b];
            }
            int start = b;
            while (true) {
                cycle.push(b);
                b = previous[b];
                if (b == start) break;
            }
            cycle.push(b);
            cout<<"YES\n";
            while (!cycle.empty()) {
                cout<<cycle.top()<<" ";
                cycle.pop();
            }
            return 0;
        }
    }
    
    cout<<"NO\n";
    
    return 0;
}

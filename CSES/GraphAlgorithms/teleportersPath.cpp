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
 
const int N = 1e5+1;
int n, m;
set<int> adj[N];
map<int,int> inDegree;
map<int,int> outDegree;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    cin>>n>>m;
    forn(i,m) {
        int a, b; cin>>a>>b;
        adj[a].insert(b);
        outDegree[a]++; 
        inDegree[b]++;
    }
    for (int i = 2; i < n; i++) {
        if (inDegree[i] != outDegree[i]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    // Outdegree de 1 debe ser mayor que indegree
    if (inDegree[1] != outDegree[1]-1) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    if (inDegree[n]-1 != outDegree[n]) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    stack<int> st;
    st.push(1);
    while(!st.empty()) {
        int v = st.top();
        if (outDegree[v] == 0) {
            ans.push_back(v);
            st.pop();
        } else {
            int u = *adj[v].begin();
            adj[v].erase(u);
            outDegree[v]--;
            inDegree[u]--;
            st.push(u);
        }
    }
    // En grafo dirigido se invierte
    reverse(ans.begin(), ans.end());
    if (ans.size() != m+1) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for (auto i : ans) cout<<i<<" ";
    cout<<"\n";
 
    return 0;
}

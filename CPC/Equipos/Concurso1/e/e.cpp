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

vector<bool> visited;
vector<vector<int> > adj;

void dfs (int s) {

    if (visited[s]) return;
    visited[s]=true;
    for (int u:adj[s]) {
        dfs(u);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;

    visited.resize(n+1);
    adj.resize(n+1);
    
    forn(i, m) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int nG=0;
    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;
        nG++;
        dfs(i);
    }
    cout<<nG-1<<endl;



}

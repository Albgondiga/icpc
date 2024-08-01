
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
#define lb lower_bound
const int MAXN=100100;

#define debug 1
const int MAX = 1e6+5;
int n;
vector<int> adj[MAX];
bool visited[MAX];
ll maxValue=0;
ll maxCount=0;

ll dfs(int x) {
    ll currentLong = 1;
    visited[x] = true;
    for (auto u : adj[x]) {
        if (visited[u]) continue;
        ll largo = dfs(u);
        currentLong += largo;

        ll res = largo * (n-largo);
        if (res == maxValue) maxCount++;
        else if (res > maxValue) {
            maxValue = res;
            maxCount = 1;
        }
    }
    return currentLong;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i, n-1) {
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);
    cout<<maxValue<<" "<<maxCount<<"\n";

    return 0;
}

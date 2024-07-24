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
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

const int MAX = 1e5+5;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];
int dist[MAX];
map<int,int> previous;

bool bfs(int start) {
    visited[start] = true;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int s = q.front(); q.pop();

        if (s == n) {
            return true;
        }

        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s]+1;
            q.push(u);
            previous[u] = s;
        }
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    int a, b;
    while(m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (bfs(1)) {
        stack<int> route;
        route.push(n);
        int s = n;
        while (s != 1) {
            route.push(previous[s]);
            s = previous[s];
        }

        cout<<dist[n]+1<<"\n";
        while (!route.empty()) {
            cout<<route.top()<<" ";
            route.pop();
        }
        cout<<"\n";
    } else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
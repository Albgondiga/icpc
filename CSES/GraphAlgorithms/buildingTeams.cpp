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
bool visited[MAX];
vector<int> adj[MAX];
int team[MAX];

bool dfs(int s) {
    bool possible = true;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (visited[u]) {
            if (team[u] == team[s]) {
                possible = false;
                return possible;
            }
        } else {
            team[u] = !team[s];
            possible = dfs(u);
            if (!possible) break;
        }
    }
    return possible;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    int a, b;
    while (m--) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool possible = true;
    for (int i = 1; i <= n && possible; i++) {
        if (!visited[i]) {
            possible = dfs(i);
        }
    }

    if (possible) {
        for (int i = 1; i <= n; i++) cout<<team[i]+1<<" ";
        cout<<"\n";
    } else {
        cout<<"IMPOSSIBLE\n";
    }

    return 0;
}
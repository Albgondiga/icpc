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

const int N = 1e5+1;
int n, m;
bool visited[N];
vector<int> adj[N];
deque<int> path;


bool dfs(int a, int parent) {
    visited[a] = true;
    path.push_back(a);
    for (auto b : adj[a]) {
        if (visited[b]) {
            if (parent != b) {
                path.push_back(b);
                return true;
            } 
        } else {
            if (dfs(b, a)) return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(i,m) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                while (!path.empty() and (path.front() != path.back()))
                    path.pop_front();
                cout<<path.size()<<"\n";
                while (!path.empty()) {
                    cout<<path.front()<<" ";
                    path.pop_front();
                }
                cout<<"\n";
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}

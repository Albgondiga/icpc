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

const int N = 5;
int h, w;
vector<vector<int>> A, B;

int bfs() {
    queue<vector<vector<int>>> q;
    set<vector<vector<int>>> visited;
    map<vector<vector<int>>, int> dist;
    visited.insert(A);
    dist[A] = 0;
    q.push(A);
    while (q.empty()) {
        vector<vector<int>>& s = q.front(); q.pop();
        for (int i = 0; i < h-1; i++) {
            
        }
        for (int i = 0; i < w-1; i++) {
            
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w;
    A.assign(h, vector<int>(w));
    forn(i,h) forn(j,w) cin>>A[i][j];
    forn(i,h) forn(j,w) cin>>B[i][j];

    cout<<bfs()<<"\n";

    return 0;
}

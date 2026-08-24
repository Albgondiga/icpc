#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

// https://codeforces.com/group/GHvtTrfZFd/contest/706415/problem/C 

const vector<int> dI = {0, 0, -1, 1}, dJ = {-1, 1, 0 , 0};

const int N = 500;
int n, m, k;
char G[N][N];
bool vis[N][N];

ii raiz;
vector<ii> nivel[N*N+1];
vector<ii> pintar;
int prof;

bool valid(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

void dfs(int i, int j, int d = 0) {
    vis[i][j] = true;
    prof = max(prof, d);
    nivel[d].push_back({i,j});
    forn(k,4) {
        if (valid(i + dI[k], j + dJ[k]) and !vis[i + dI[k]][j + dJ[k]] and G[i + dI[k]][j + dJ[k]] == '.') {
            dfs(i + dI[k], j + dJ[k], d+1);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k;
    forn(i,n) forn(j,m) {
        vis[i][j] = false;
        cin>>G[i][j];
        if (G[i][j] == '.') raiz = {i,j};
    }
    
    prof = 0;
    dfs(raiz.first, raiz.second);

    while (k) {
        if (nivel[prof].empty()) {
            prof--;
        } else {
            pintar.push_back(nivel[prof][nivel[prof].size()-1]);
            nivel[prof].pop_back();
            k--;
        }
    }

    for (const ii& x : pintar) G[x.first][x.second] = 'X';
    
    forn(i,n) {
        forn(j,m) {
            cout<<G[i][j];
        }
        cout<<"\n";
    }

    return 0;
}

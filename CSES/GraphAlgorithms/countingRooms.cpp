
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

int n, m;
const int MAX = 1000;
bool visited[MAX][MAX];
char grid[MAX][MAX];

const int dI[4] = { -1, 1, 0, 0 };
const int dJ[4] = { 0, 0, 1, -1 };

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}

void dfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    forn (k, 4) {
        if (isValid(i+dI[k],j+dJ[k])) {
            dfs(i+dI[k],j+dJ[k]);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(i,n) forn(j,m) cin>>grid[i][j];
    
    ll count = 0;
    forn (i,n) {
        forn (j,m) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<"\n";

    return 0;
}
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

#define Z 0
#define X 1
#define Y 2

#define U 0
#define D 1
#define L 2
#define R 3

const int MAXN = 1000+5;
int dist[MAXN][MAXN];
bool blocked[MAXN][MAXN];
bool visited[MAXN][MAXN][3];
int n, m;
ii c, e;

map<ii,pair<ii,char>> previous;

const int dI[4] = {-1, 1, 0, 0};
const int dJ[4] = {0, 0, -1, 1};
const char dir[4] = {'U','D','L','R'};

bool isValid(int x, int y, int orientation) {
    return (x >= 0 && x < n && y >= 0 && y < m && !blocked[x][y] && !visited[x][y][orientation]);
}

bool bfs(ii start) {
    queue<pair<ii,int>> q;
    visited[start.first][start.second][Z] = true;
    dist[start.first][start.second] = 0;
    q.push({start,Z});
    while(!q.empty()) {
        pair<ii,int> s = q.front(); q.pop();
        int i = s.first.first, j = s.first.second, ori = s.second;
        
        if (i == e.first && j == e.second) {
            return true;
        }

        for (int k = 0; k < 4; k++) {

            if (ori == X) {
                
            } else if (ori == Y) {

            } else { // ori == Z

            }

            if (isValid(i+dI[k],j+dJ[k])) {
                if (visited[i+dI[k]][j+dJ[k]]) continue;
                visited[i+dI[k]][j+dJ[k]] = true;
                previous[{i+dI[k],j+dJ[k]}] = {s, dir[k]};
                dist[i+dI[k]][j+dJ[k]] = dist[i][j]+1;
                q.push({i+dI[k],j+dJ[k]});
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(i,n) {
        forn(j,m) {
            char next; cin>>next;
            if (next == '#') blocked[i][j] = true;
            else if (next == 'C') c = {i,j};
            else if (next == 'E') e = {i,j};
        }
    }
  
    if (bfs(c)) {
        cout<<dist[e.first][e.second]<<"\n";
        ii step = e;
        stack<char> path;
        while (dist[step.first][step.second] != 0) {
            path.push(previous[step].second);
            step = previous[step].first;
        }
        while (!path.empty()) {
            cout<<path.top(); path.pop();
        }
        cout<<"\n";
    } else {
        cout<<-1<<"\n";
    }

    return 0;
}

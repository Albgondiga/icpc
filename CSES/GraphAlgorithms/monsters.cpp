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

const int INF = 1e6;
const int N = 1000;
int n, m;
ii a, last;
char graph[N][N];
int dist[N][N];
queue<ii> monsters;
bool visitedMonsters[N][N];
int distMonsters[N][N];

map<ii,pair<ii,char>> previous;

const int dI[4] = {-1, 1, 0, 0};
const int dJ[4] = {0, 0, -1, 1};
const char dir[4] = {'U','D','L','R'};

bool isValid(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and graph[i][j] == '.');
}

void bfsMonsters() {
    while(!monsters.empty()) {
        ii s = monsters.front(); monsters.pop();
        int i = s.first, j = s.second;
        for (int k = 0; k < 4; k++) {
            if (isValid(i+dI[k],j+dJ[k])) {
                if (visitedMonsters[i+dI[k]][j+dJ[k]]) continue;
                visitedMonsters[i+dI[k]][j+dJ[k]] = true;
                distMonsters[i+dI[k]][j+dJ[k]] = distMonsters[i][j]+1;
                monsters.push({i+dI[k],j+dJ[k]});
            }
        }
    }
}

bool bfs() {
    bool visited[N][N] = {0};
    queue<ii> q;
    visited[a.first][a.second] = true;
    q.push(a);
    while(!q.empty()) {
        ii s = q.front(); q.pop();
        int i = s.first, j = s.second;

        if (i == 0 or i == n-1 or j == 0 or j == m-1) {
            last = {i,j};
            return true;
        }
        
        for (int k = 0; k < 4; k++) {
            if (isValid(i+dI[k],j+dJ[k])) {
                if (visited[i+dI[k]][j+dJ[k]]) continue;
                visited[i+dI[k]][j+dJ[k]] = true;
                if (dist[i][j]+1 < distMonsters[i+dI[k]][j+dJ[k]]) {
                    dist[i+dI[k]][j+dJ[k]] = dist[i][j]+1;
                    previous[{i+dI[k],j+dJ[k]}] = {s,dir[k]};
                    q.push({i+dI[k],j+dJ[k]});
                }
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
            char c; cin>>c;
            graph[i][j] = c;
            if (c == 'A') {
                a = {i,j};
            } else if (c == 'M') {
                distMonsters[i][j] = 0;
                visitedMonsters[i][j] = true;
                monsters.push({i,j});
            } else {  // c == '.'
                distMonsters[i][j] = INF;
            }
        }
    }

    bfsMonsters();
    bool found = bfs();

    if (found) {
        cout<<"YES\n";
        cout<<dist[last.first][last.second]<<"\n";
        ii step = last;
        stack<char> path;
        while (dist[step.first][step.second] != 0) {
            path.push(previous[step].second);
            step = previous[step].first;
        }
        while (!path.empty()) {
            cout<<path.top(); path.pop();
        }
    } 
    else cout<<"NO\n";

    return 0;
}

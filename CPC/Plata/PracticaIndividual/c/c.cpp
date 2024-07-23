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

#define debug 0
#define ifd if (debug)

const int MAX = 1000+5;
bool visited[MAX][MAX];
char graph[MAX][MAX];
int dist[MAX][MAX];
int n, m;
ii a, b;

map<ii,pair<ii,char>> previous;

const int dI[4] = {-1, 1, 0, 0};
const int dJ[4] = {0, 0, -1, 1};
const char dir[4] = {'U','D','L','R'};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != '#' && !visited[x][y]);
}

bool bfs(ii start) {
    queue<ii> q;
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    q.push(start);
    while(!q.empty()) {
        ii s = q.front(); q.pop();
        int i = s.first, j = s.second;
        ifd if (s != a) cout<<"Estoy viendo la posicion ("<<i<<","<<j<<"), ";
        ifd if (s != a) cout<<"llegue desde ("<<previous[s].first.first<<","<<previous[s].first.second<<") + "<<previous[s].second<<endl;
        if (b.first == i && b.second == j) {
            return true;
        }

        for (int k = 0; k < 4; k++) {
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
            graph[i][j] = next;
            if (next == 'A') a = {i,j};
            else if (next == 'B') b = {i,j};
        }
    }

    if (bfs(a)) {
        cout<<"YES\n";
        cout<<dist[b.first][b.second]<<"\n";
        ii step = b;
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
        cout<<"NO\n";
    }

    return 0;
}

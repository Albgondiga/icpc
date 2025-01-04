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

const int N = 500+1;
const int INF = 1e9;
int n;
char grid[N][N];
int dist[N][N];
bool processed[N][N];

const int dI[4] = {-1,1,0,0};
const int dJ[4] = {0,0,-1,1};

bool isValid(int i, int j) {
    return ((i >= 1) && (i <= n) && (j >= 1) && (j <= n));
}

int dijkstra(int begI, int begJ, int endI, int endJ, char color) {
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)  {
            dist[i][j] = INF; 
            processed[i][j] = false;
        }
    }
    priority_queue<tuple<int,int,int>> q;
    dist[begI][begJ] = 0;
    q.push({0,begI,begJ});
    while (!q.empty()) {
        int ai = get<1>(q.top());
        int aj = get<2>(q.top());
        q.pop();
        if (processed[ai][aj]) continue;
        processed[ai][aj] = true;
        for (int k = 0; k < 4; k++) {
            int bi = ai+dI[k];
            int bj = aj+dJ[k];
            if (isValid(bi, bj)) {
                int isPurple = 0; 
                if (grid[bi][bj] != color) isPurple++;
                if (dist[ai][aj]+isPurple < dist[bi][bj]) {
                    dist[bi][bj] = (dist[ai][aj]+isPurple);
                    q.push({-dist[bi][bj],bi,bj});
                }
            }
        }
    }
    return dist[endI][endJ];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            cin>>grid[i][j];

    // Dijkstra donde distancia es la cantidad de casillas que
    // se cambian a morado
    cout<<dijkstra(1,1,n,n,'R')+dijkstra(1,n,n,1,'B')<<"\n";

    return 0;
}

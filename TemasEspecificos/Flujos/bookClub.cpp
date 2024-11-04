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

// https://codeforces.com/gym/100783

const int MAX = 2e4+5;
const int oo = 1e9;
const int mod = 1e9+7;

vector <int> G[MAX];

int n, m; //n left, m right nodes
int M[MAX], A[MAX]; //match

bool bfs() {
    queue<int> Q;
    for(int i = 1; i <= n * 2; i++)
        if(M[i] == 0)
            A[i] = 0, Q.push(i);
        else
            A[i] = oo;
    A[0] = oo;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i : G[u])
            if(A[M[i]] == oo) {
                A[M[i]] = A[u] + 1;
                Q.push(M[i]);
            }
    }
    return (A[0] != oo);
}

bool dfs(int u) {
    if(!u) return 1;
    for(int i : G[u])
        if(A[M[i]] == A[u] + 1 && dfs(M[i])) {
            M[i] = u;
            M[u] = i;
            return 1;
        }
    A[u] = oo;
    return 0;
}

int hopcroft_karp() {
    int r = 0;
//    memset(M, 0, sizeof M); //done in push
    while(bfs())
        for(int i = 1; i <= n * 2; i++)
            if(M[i] == 0 && dfs(i))
                r++;
    return r;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Hopcroft-Karp: perfect matching 
    // Izquierda: nodos que prestan
    // Derecha: nodos que reciben
    cin>>n>>m;
    forn(i,m) {
        int a, b; cin>>a>>b;
        a++; b++;  // 1-indexed
        G[b].pb(n+a);
    }

    int ans = hopcroft_karp();
    if (ans == n) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}
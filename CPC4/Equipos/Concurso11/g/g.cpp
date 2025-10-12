// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

ll hashsillo(string&s) {
    s[0]=tolower(s[0]);
    ll ans =0;
    ll MOD = 999727999;
    ll P = 1777771;
    forn(i, s.size()) {
        ans = (ans *P)%MOD;
        ans =(ans + (s[i]-'a'))%MOD;
    }

    return ans;
}

const int N = 1e5+1;

// sig va a quedar en ultimo nodo
int sig = 0;

// Mapa de hash a indice
map<ll,int> idx;

bool visited[N];
vector<int> adj[N];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (visited[u]) continue;
        dfs(u);
    }
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;

    set<ll> hashes;
    forn(i, n) {
        string a; cin>>a; a.pop_back();
        string trash; cin>>trash>>trash;
        string b; cin>>b;

        ll hA = hashsillo(a), hB=hashsillo(b);

        if (hashes.find(hA) == hashes.end()) idx[hA] = ++sig;
        hashes.insert(hA);
        if (hashes.find(hB) == hashes.end()) idx[hB] = ++sig;
        hashes.insert(hB);

        // A es hijo de B
        adj[idx[hB]].push_back(idx[hA]);

    }

    for (int i = 1; i <= sig; i++) visited[i] = false;
    int ultimo = 0;
    for (int i = 1; i <= sig; i++) {
        if (not visited[i]) {
            ultimo = i;
            dfs(i);
        }
    }

    // El ultimo nodo que empieza un dfs tiene que ser la raiz
    for (int i = 1; i <= sig; i++) visited[i] = false;
    dfs(ultimo);
    for (int i = 1; i <= sig; i++) {
        if (not visited[i]) {
            cout<<"impossible\n";
            return 0;
        }
    }

    cout<<"possible\n";

    return 0;
}

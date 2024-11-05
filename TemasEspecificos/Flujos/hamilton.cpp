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

#define debug 0
#define ifd if (debug)

// https://codeforces.com/gym/103640/problem/H

const ll INF = 1e18;
const int MAX= 505+5;
ll n, m;
ll tamano;
ll A[MAX][MAX];
ll edges[MAX][MAX];

vector<ll> hungarian() {
    vector<ll> u (MAX), v (MAX), p (MAX), way (MAX);
    for (ll i=1; i<=n; ++i) {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv (MAX, INF);
        vector<bool> used (MAX, false);
        do {
            used[j0] = true;
            ll i0 = p[j0],  delta = INF,  j1;
            for (ll j=1; j<=m; ++j)
                if (!used[j]) {
                    ll cur = A[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (ll j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    return p;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int otroN; cin>>otroN;
    for (int i = 1; i <= otroN; i++) {
        for (int j = 1; j <= otroN; j++) {
            cin>>edges[i][j];
        }
    }

    // Empiezo a contar los nodos en 0
    for (int i = 1; i <= otroN; i += 2) edges[i][0] = 0;
    if (otroN % 2) {
        // Si otroN es impar agrego un nodo dummy par al final
        for (int i = 1; i <= otroN; i += 2) edges[i][otroN+1] = 0;
        otroN++;
    }

    n = otroN/2;
    m = otroN/2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = edges[(i-1)*2+1][j*2-2] + edges[(i-1)*2+1][j*2];
        }
    }

    vector<ll> p = hungarian();
    vector<ll> ans(MAX);
    for (int j=1; j<=m; ++j)
        ans[p[j]] = j;

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += A[i][ans[i]];
    }

    cout<<res<<"\n";

    return 0;
}

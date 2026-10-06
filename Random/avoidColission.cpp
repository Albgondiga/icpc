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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

// https://codeforces.com/gym/106677/problem/G

const ll MOD = 998244353;

int n, m;
vector<vector<char>> M;
// Matrices 1 me dicen en cada casilla, de cuantas formas puede llegar la ficha ahi
// Matrices 2 me dicen en cada casilla, de cuantas formas puede llegar la ficha al final desde ahi
vector<ll> blanca1, blanca2, negra1, negra2;
inline int id(int i, int j) { return i*m + j; }

void precalc() {
    blanca1.assign(n*m, 0); blanca2.assign(n*m, 0);
    negra1.assign(n*m, 0);  negra2.assign(n*m, 0);

    // blanca1: formas de llegar desde (0,0) bajando / yendo a la derecha
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (M[i][j] == '#') continue;
        ll count = (i == 0 and j == 0);
        if (j > 0) count += blanca1[id(i, j-1)];
        count %= MOD;
        if (i > 0) count += blanca1[id(i-1, j)];
        count %= MOD;
        blanca1[id(i, j)] = (count % MOD);
    }
    // blanca2: formas de ir de (i,j) a (n-1,m-1)
    for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--) {
        if (M[i][j] == '#') continue;
        ll count = (i == n-1 and j == m-1);
        if (j+1 < m) count += blanca2[id(i, j+1)];
        count %= MOD;
        if (i+1 < n) count += blanca2[id(i+1, j)];
        count %= MOD;
        blanca2[id(i, j)] = (count % MOD);
    }
    // negra1: formas de llegar desde (n-1,0) subiendo / yendo a la derecha
    for (int i = n-1; i >= 0; i--) for (int j = 0; j < m; j++) {
        if (M[i][j] == '#') continue;
        ll count = (i == n-1 and j == 0);
        if (j > 0) count += negra1[id(i, j-1)];
        count %= MOD;
        if (i+1 < n) count += negra1[id(i+1, j)];
        count %= MOD;
        negra1[id(i, j)] = (count % MOD);
    }
    // negra2: formas de ir de (i,j) a (0,m-1)
    for (int i = 0; i < n; i++) for (int j = m-1; j >= 0; j--) {
        if (M[i][j] == '#') continue;
        ll count = (i == 0 and j == m-1);
        if (j+1 < m) count += negra2[id(i, j+1)];
        count %= MOD;
        if (i > 0) count += negra2[id(i-1, j)];
        count %= MOD;
        negra2[id(i, j)] = (count % MOD);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin>>n>>m;
        if (n == 0 and m == 0) break;
        M.assign(n, vector<char>(m));
        forn(i,n) forn(j,m) cin>>M[i][j];
        
        precalc();

        int mid = n/2;
        ll ans = (blanca1[id(n-1, m-1)] * negra1[id(0, m-1)]) % MOD;

        forn(j, m) {
            // pares que comparten la casilla (mid, j)
            ll b = (blanca1[id(mid, j)] * blanca2[id(mid, j)]) % MOD;
            ll ne = (negra1[id(mid, j)] * negra2[id(mid, j)]) % MOD;
            ans = (ans - b * ne) % MOD;
            // pares que comparten la arista (mid, j) -> (mid, j+1)
            if (j + 1 < m) {
                b  = blanca1[id(mid, j)] * blanca2[id(mid, j+1)] % MOD;
                ne = negra1[id(mid, j)] * negra2[id(mid, j+1)] % MOD;
                ans = (ans + b * ne) % MOD;
            }
        }

        cout<<((ans % MOD + MOD) % MOD)<<"\n";
    }

    return 0;
}

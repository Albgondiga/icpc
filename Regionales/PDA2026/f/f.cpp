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

#define debug 0
#define ifd if (debug)

const int N = 150+1;
const int DIM = 17;

// base es tamano de la base, sig es la siguiente bola a colocar
// k es el siguiente bit de la mascara
int n, base, sig, k;
int color[N];
/*
Por comodidad la base de la matriz esta en la primera fila 
La piramide se mantiene siempre pegada a la esquina superior izquierda
Ej: ***
    **
    *
*/
int m[DIM][DIM];

void moverM() {
    for (int i = 0; i < k; i++) {
        for (int j = k+1; j >= 1; j--) {
            m[i][j] = m[i][j-1];
        }
        m[i][0] = 0;
    }
}

// bit prendido = lo pongo a la izq
void diagonal(int bit, int k) {
    // Cantidad de gente que voy a poner en la diagonal
    int count = k+1;
    if (bit) {
        moverM();
        int i = 0, j = 0;
        while (count and sig <= n) {
            m[i][j] = sig;
            i += 1, j += 1;
            sig++;
            count--;
        }
    } else { // Derecha
        // Note que si pongo a la derecha, la diagonal empieza en (0,k)
        // donde k es el bit de la mascara en el que estoy
        int i = 0, j = k;
        while (count and sig <= n) {
            m[i][j] = sig;
            i += 1, j -= 1;
            sig++;
            count--;
        }
    }
}

int dfs(int i, int j) {
    int ans = 1;
    int miColor = color[m[i][j]];
    // Borro el color (equivlente a vis = true)
    m[i][j] = 0;
    // Me fijo a los lados
    if (j > 0 and color[m[i][j-1]] == miColor) ans += dfs(i,j-1);
    if (j < base and color[m[i][j+1]] == miColor) ans += dfs(i,j+1);
    // Me fijo en los adyacentes de abajo (abajo y abajo a la izquierda)
    if (i < base) {
        if (color[m[i+1][j]] == miColor) ans += dfs(i+1,j);
        if (j > 0 and color[m[i+1][j-1]] == miColor) ans += dfs(i+1,j-1);
    }
    return ans;
}

int maxComp() {
    int ans = 0;
    forn(i,base) forn(j,base) {
        // Despinto el componente de todos los que me encuentro pintados
        if (m[i][j] != 0) {
            ans = max(ans, dfs(i,j));
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n) cin>>color[i+1];

    base = 1;
    // Precalculo el tamano de la base
    while ((base*(base+1))/2 < n) base++;

    int mask = 0, ans = 0;
    while (mask < (1 << base)) {
        // Limpio la matriz
        // forn(i,n) forn(j,n) m[i][j] = 0;
        // Sig tiene cual bola es la siguiente
        sig = 1;
        // Pongo base bolas en la base
        k = 0;
        while (k < base) {
            // Si se me acabaron las bolas termino (por ai acaso)
            if (sig > n) break;
            // Pongo la diagonal
            diagonal(mask & (1 << k), k);
            k++;
        }
        int nuevoAns = maxComp();
        ans = max(ans, nuevoAns);
        mask++;
    }

    cout<<ans<<"\n";

    return 0;
}

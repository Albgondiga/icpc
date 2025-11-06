#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/E

const int N = 2e5+5;

// Cual mono esta en mano izq/der
int monkey[N][2];
// edge[{i,j}] guarda cuantas aristas hay entre los monos i y j
map<ii,int> edge;

// No podemos actualizar todos los miembros de un conjunto al hacer add
// Guardamos la diferencia de experiencia entre cada nodo y su representante
// extra[i] tiene los puntos de i adicionales a los del papa
// pts[i] tiene los puntos acumulados del grupo del rep i
int link[N], r[N], extra[N], pts[N];

// Cuando hacemos find, de una vez le sumamos lo que le hemos sumado al grupo
// Lo que le hemos sumado al grupo esta en el extra del papa
int find(int a) {
    if (link[a] == a) return a;
    return find(link[a]);
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    if (!same(a,b)) {
        a = find(a), b = find(b);
        if (r[a] == r[b]) r[a]++;
        if (r[a] < r[b]) swap(a,b);
        link[b] = a;
        extra[b] = pts[a];
    }
}

void add(int a, int v) {
    pts[find(a)] += v;
}

int get(int a) {
    if (a == link[a]) return pts[a];
    else return (pts[a]-extra[a])+get(link[a]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        int l, r; cin>>l>>r;
        
        monkey[i][0] = l;
        monkey[i][1] = l;

        if (l != -1) edge[{min(i,l),max(i,l)}]++;
        if (r != -1) edge[{min(i,r),max(i,r)}]++;
    }
    forn(i,m) {
        int id, h; cin>>id>>h;
        int u = id, v = monkey[id][h];
        edge[{min(u,v),max(u,v)}]--;
        
    }


    return 0;
}

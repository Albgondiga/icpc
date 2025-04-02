#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const ld INF = (ld) 1e18;
int n, r;

// un punto con coordenadas x y
struct pt {ld x, y;};

// POLARSORT: un punto es menor a otro fijándose por x primero, luego por y
bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);}

// me dice si el giro a -> b -> c es clockwise 
bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;}

// me dice si el giro a -> b -> c es counter clockwise 
bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), &cmp);
    // p1 punto mas izquierdo, p2 mas derecho
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down; up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);}
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);}}
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

// p1-p2
pt restar(pt p1, pt p2) {
    pt p = {p1.x - p2.x, p1.y - p2.y};
    return p;
}

ld cruz(pt p1, pt p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

ld norma(pt p) {
    return sqrtf(p.x*p.x + p.y*p.y);
}

// Calcula la distancia perpendicular de p a la linea de s1 a s2
ld distancia(pt s1, pt s2, pt p) {
    // (s1-p)x(s2-p)/|s2-s1|
    return abs( cruz(restar(s1,p), restar(s2,p)) / norma(restar(s2,s1)) );
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>r;
    vector<pt> a(n);
    for (pt& p : a) {
        cin>>p.x>>p.y;
    }

    convex_hull(a);

    ld ans = INF;

    // Nota: no muevo p si la siguiente distancia es menor

    int s1 = 0, s2 = 1, p = 2;
    // Recorrer el poligono por lados
    while (true) {
        ld distanciaActual = 0.0;
        // Buscar el punto mas lejano del lado actual
        while (p != s1) {
            ld nuevaDistancia = distancia(a[s1],a[s2],a[p]);
            // Si la distancia de p es mayor que la distancia maxima actual
            if (nuevaDistancia > distanciaActual) {
                // Se actualiza y se mueve p
                distanciaActual = nuevaDistancia;
                p++;
                // Por si le da la vuelta al poligono
                if (p == a.size()) p = 0;
            } else {
                // Si no mejora la distancia hasta aqui llega
                break;
            }
        }
        // Actualizar ans
        ans = min(ans, distanciaActual);
        
        // Moverse al siguiente lado
        s1++; 
        s2++;
        // Por si le da la vuelta al poligono
        if (s1 == a.size()) s1 = 0;
        if (s2 == a.size()) s2 = 0;

        // Condicion de parada
        if (s1 == 0 and s2 == 1) break; 

        // Recuerdo el ultimo p que funciono
        int anterior = (p-1 < 0 ? a.size()-1 : p-1);
        if (anterior != s1 and anterior != s2) p = anterior;
    }

    cout<<setprecision(16)<<fixed<<ans<<"\n";
    return 0;
}

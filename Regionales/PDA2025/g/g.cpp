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

#define debug 1
#define ifd if (debug)

#define a first.first
#define b first.second
#define h second

typedef std::set<std::pair<std::pair<ll, ll>, ll>>::iterator I;

// https://codeforces.com/gym/105789/problem/G

const ll INF = 1e18;

int n;
char tipo;
ll l, p; 
set<pair<pair<ll,ll>, ll>> bloques;

void generarIt(I& actual, I& antes, I& despues, ll i, ll j) {
    if (bloques.size()) 
        if (despues != bloques.begin()) 
            actual = prev(despues);
        if (actual != bloques.begin() and despues != bloques.begin()) 
            antes = prev(actual);

    if (actual != bloques.end()) {
        if (actual->b < i) {
            antes = actual;
            actual = bloques.end();
        }
    }    
}

void insertar(I& actual, I& antes, I& despues, ll i, ll j, ll altura) {
    bool pegadoI = false, pegadoD = false;
    if (antes != bloques.end()) {
        if (antes->b == i-1 and antes->h == altura) {
            i = antes->a;
            bloques.erase(antes);
            pegadoI = true;
        }
    }
    if (despues != bloques.end()) {
        if (despues->a == j+1 and despues->h == altura) {
            j = despues->b;
            bloques.erase(despues);
            pegadoD = true;
        }
    }
    // Partir el bloque actual si es necesario
    if (!pegadoI) 
        if (actual != bloques.end() and actual->a < i)
            bloques.insert({{actual->a, i-1}, actual->h});
    if (!pegadoD) 
        if (actual != bloques.end() and actual->b > j)
            bloques.insert({{j+1, actual->b}, actual->h});
    if (actual != bloques.end()) bloques.erase(actual);
    bloques.insert({{i,j},altura});
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    string ans = "";

    for (int cont = 0; cont < n; cont++) {
        cin>>tipo>>l>>p;

        ll i = p, j = ((tipo == '|') ? p : p+l-1), altura = ((tipo == '|') ? l : 1);
        I actual = bloques.end(), antes = bloques.end(), 
            despues = bloques.upper_bound({{j,INF},0});

        generarIt(actual, antes, despues, i, j);

        if (actual != bloques.end()) altura += actual->h;

        if (tipo == '|') {
            insertar(actual, antes, despues, i, j, altura);
            ans += 'S';
        } else {
            if (antes != bloques.end() and antes->b >= i) {
                ans += 'U';
                continue;
            }
            if (actual != bloques.end() and (actual->a > i or actual->b < j)) {
                ans += 'U';
                continue;
            }
            if (despues != bloques.end() and despues->a <= j) {
                ans += 'U';
                continue;
            }
            insertar(actual, antes, despues, i, j, altura);
            ans += 'S';
        }
    }
  
    cout<<ans<<"\n";
    return 0;
}

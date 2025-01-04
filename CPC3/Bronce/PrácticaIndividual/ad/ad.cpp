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

#define debug 1
#define ifd if (debug)

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    
    int n, cant_ady[MAX] = { 0 }; 
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        cant_ady[x]++;
        cant_ady[y]++;
    }

    int cant_colores = 0;
    for (int i = 1; i <= n; i++) {
        cant_colores = max(cant_colores, cant_ady[i] + 1);
    }

    cout << cant_colores << '\n';
}
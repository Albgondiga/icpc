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
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    cout<<0<<"\n";
    if (n >= 2) {
        cout<<6<<"\n";
        for (ll i = 3; i <= n; i++) {
            // Todas las formas de poner caballos
            ll total = i*i*(i*i-1)/2;
            // Todos las formas de matarse en cuadrados 2x3 (2 c/u)
            ll horizontal = 2*(i-1)*(i-2);
            // Todos las formas de matarse en cuadrados 3x2 (2 c/u)
            ll vertical = 2*(i-2)*(i-1);

            cout<<total-horizontal-vertical<<"\n";
        }
    }
}
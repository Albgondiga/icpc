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
typedef long long int ll;
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
    // Cuando se divide n no se consideran todos los multiplos de primos
    // => no hace falta criba
    for(ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            cout<<i<<"\n";
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1)
        cout<<n<<"\n";
    return 0;
}
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

// void countDivisors(ll x, vector<ll>& d) {
//     ll count = 0;
//     for(ll d = 1; d*d <= x; d++) {
//         if (x % d == 0) {
//             count++;
//             if (d*d != x)
//                 count++; 
//         }
//     }
//     d[x] = count;
// }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector<ll> d(1000001,0);
    for(int i = 1; i <= 1000000; i++) {
        for(int j = i; j <= 1000000; j+=i) {
            d[j]++;
        }
    }

    ll n; cin>>n;
    forn(i,n) {
        ll x; cin>>x;
        cout<<d[x]<<"\n";
    }
}
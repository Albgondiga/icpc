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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll l, o, s, t; cin>>l>>o>>s>>t;
    ll count = 0;
    if (l >= 2 && s >= 2) {
        ll x = min(l/2, s/2);
        count += x;
        l -= 2*x;
        s -= 2*x;
    }
    if (l >= 2 && o >= 2) {
        ll x = min(l/2, o/2);
        count += x;
        l -= 2*x;
        o -= 2*x;
    }
    if (l >= 4) {
        ll x = l/4;
        count += x;
        l -= 4*x;
    }
    if (o >= 4) {
        ll x = o/4;
        count += x;
        o -= 4*x;
    }
    if (t >= 4) {
        ll x = t/4;
        count += x;
        t -= 4*x;
    }
    if (l >= 1 && s >= 1 && t >= 2) {
        ll x = min(l, min(s, t/2));
        count += x;
        l -= x;
        s -= x;
        t -= 2*x;
    }

    cout<<count<<"\n";

    return 0;

}

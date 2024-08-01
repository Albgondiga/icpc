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

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll d, m, d1, n, d2; cin>>d>>m>>d1>>n>>d2;

    ll distance = 2*d;
    if (m*d1 >= distance) {
        ll count = ceil((double)distance/d1);
        if (count == 0) count = 1;
        cout<<count<<"\n";
    } else {
        distance -= (m*d1);
        distance *= 2;

        ll count = ceil((double)distance/d2);
        if (count == 0) count = 1;
        if (count <= n) cout<<m+count<<"\n";
        else cout<<-1<<"\n";
    }

    return 0;
}
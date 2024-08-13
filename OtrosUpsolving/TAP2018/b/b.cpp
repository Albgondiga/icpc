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
    
    ll dist = d;
    ifd cout<<"dist = "<<dist<<endl;
    ll pow = 2, count = 0;
    while (m > 0 && dist > 0) {
        if (d1 <= dist) break;
        count++;
        dist = pow*(d-d1)+d1;
        ifd cout<<"count = "<<count<<", dist = "<<dist<<endl;
        pow *= 2;
        m--;
    }

    pow = 2; d = dist;
    while (n > 0 && dist > 0) {
        if (d2 <= dist) break;
        count++;
        dist = pow*(d-d2)+d2;
        ifd cout<<"count = "<<count<<", dist = "<<dist<<endl;
        pow *= 2;
        n--;
    }

    if (dist <= 0) cout<<count<<"\n";
    else cout<<-1<<"\n";

    return 0;
}
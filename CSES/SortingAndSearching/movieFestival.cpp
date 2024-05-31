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

bool compare(pll& p1, pll& p2) {
    return p1.second < p2.second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    vector<pll> v;

    forn(i,n) {
        ll a,b; cin>>a>>b;
        v.pb(mp(a,b));
    }

    sort(v.begin(), v.end(), compare);

    ll count = 0;
    ll time = 0;
    auto i = v.begin();
    while (i != v.end()) {
        ifd cout<<"time="<<time<<endl;
        if ((*i).first >= time) {
            count++;
            time = (*i).second;
        }
        i++;
    }
    cout<<count<<"\n";
    return 0;
}

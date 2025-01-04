#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pf push_front
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define mp make_pair
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    deque<pll> dq;
    //ifd cout<<"max_size="<<dq.max_size()<<endl;
    ll n; cin>>n;
    forn(i,n) {
        ll inst; cin >> inst;
        if (inst == 1) {
            ll x, c; cin>>x>>c;
            dq.pb(mp(x,c));
            // if (!dq.empty() && (dq.front().first == x)) {
            //     ll cf = dq.front().second;
            //     dq.pop_front();
            //     dq.pf(mp(x,cf+c));
            // } else {
            //     dq.pb(mp(x,c));
            // }
        } else {
            ll c; cin>>c;
            ll result = 0;
            while (c) {
                if (!dq.empty()) {
                    ll xf = dq.front().first;
                    ll cf = dq.front().second;
                    if (c < cf) {
                        result += c*xf;
                        dq.pop_front();
                        dq.pf(mp(xf,cf-c));
                        c = 0;
                    } else {
                        result += cf*xf;
                        c -= cf;
                        dq.pop_front();
                    }
                }
            }
            cout<<result<<"\n";
        }
    }
    return 0;
}

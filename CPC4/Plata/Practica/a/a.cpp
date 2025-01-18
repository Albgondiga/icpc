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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

vector<pll> grass;
ll n, m; 

bool cmp(const pll p, ll x) {
    return p.first < x;
}

bool check(ll d) {
    ll cur = grass[0].first;
    ll next = cur+d;
    ll vacas = 1;
    
    while (vacas < n) {
        auto i1 = lower_bound(grass.begin(), grass.end(), next, cmp);
        i1--;
        if (i1->second >= next) {
            ifd cout<<"(1) Voy a poner la vaca en "<<next<<endl;
            cur = next;
            next = cur+d;
        } else {
            i1++;
            if (i1 == grass.end()) return false;
            ifd cout<<"(2) Voy a poner la vaca en "<<i1->first<<endl;
            cur = i1->first;
            next = cur+d;
        }
        vacas++;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    std::ifstream input("socdist.in");
    std::ofstream output("socdist.out");

    cin>>n>>m;
    grass.resize(m);
    forn(i,m) {
        ll a, b; cin>>a>>b;
        grass[i] = {a, b};
    }

    ll l = 1, r = 1e18, d = 0;
    while (l <= r) {
        ll m = l+(r-l)/2;
        if (check(m)) {
            l = m+1; d = m;
        } else {
            r = m-1;    
        }
    }

    cout<<d<<endl;
    input.close();
    output.close();

    return 0;
}

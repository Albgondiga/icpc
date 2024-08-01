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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>

#define debug 0
#define ifd if (debug)

const int INF = 1e9+5;
const int MINF = -1;

bool comp(pll p1, pll p2) {
    if (p1.first < p2.first) {
        return true;
    } else if (p1.first == p2.first) {
        if (p1.second < p2.second) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;

    vector<pll> v(n);
    map<pll,int> pos;
    forn(i,n) {
        ll a, b; cin>>a>>b;
        v[i] = {a,b};
        pos[{a,b}] = i;
    } 

    vector<int> contains(n), contained(n);
    sort(v.begin(), v.end(), comp);

    ordered_set rightBoundaries;
    for (int i = n-1; i >= 0; i--) {
        rightBoundaries.insert( {v[i].second, -1*i} );
        contains[pos[v[i]]] = rightBoundaries.order_of_key({v[i].second, -1*i});
    }

    rightBoundaries.clear();
    for (int i = 0; i < n; i++) {
        rightBoundaries.insert( {v[i].second, -1*i} );
        contained[pos[v[i]]] = (rightBoundaries.size() - rightBoundaries.order_of_key({v[i].second, -1*i}) - 1);
    }

    for(auto i:contains) cout<<i<<" ";
    cout<<"\n";
    for(auto i:contained) cout<<i<<" ";
    cout<<"\n";

    return 0;
}
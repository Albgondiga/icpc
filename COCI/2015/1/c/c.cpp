#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

map<int, set<int>> m;
vector<int> v;

void pop(int h, int i) {
    if (m[h].empty()) return;
    auto it = m[h].lower_bound(i);
    if (it == m[h].end()) return;
    int j = *it;
    m[h].erase(it);
    v[j] = 0;
    pop(h-1, j);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    v.resize(n);
    forn(i,n) {
        cin>>v[i];
        m[v[i]].insert(i);
    }

    int ans = 0;
    forn(i,n) {
        if (v[i] == 0) continue;
        ans++;
        pop(v[i], i);
    }
    cout<<ans<<"\n";

    return 0;
}

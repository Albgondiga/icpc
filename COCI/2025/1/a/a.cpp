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

#define AABB 0
#define ABAB 1
#define ABBA 2

int n, m, k;
vector<string> v(4);

int aabb() {
    int s1 = v[0].size(), s2 = v[1].size();
    for(int i = 1; i <= k; i++) {
        if (v[0][s1-i] != v[1][s2-i]) return 0;
    }
    s1 = v[2].size(), s2 = v[3].size();
    for(int i = 1; i <= k; i++) {
        if (v[2][s1-i] != v[3][s2-i]) return 0;
    }
    return 1;
}

int abab() {
    int s1 = v[0].size(), s2 = v[2].size();
    for(int i = 1; i <= k; i++) {
        if (v[0][s1-i] != v[2][s2-i]) return 0;
    }
    s1 = v[1].size(), s2 = v[3].size();
    for(int i = 1; i <= k; i++) {
        if (v[1][s1-i] != v[3][s2-i]) return 0;
    }
    return 1;
}

int abba() {
    int s1 = v[0].size(), s2 = v[3].size();
    for(int i = 1; i <= k; i++) {
        if (v[0][s1-i] != v[3][s2-i]) return 0;
    }
    s1 = v[1].size(), s2 = v[2].size();
    for(int i = 1; i <= k; i++) {
        if (v[1][s1-i] != v[2][s2-i]) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k;

    vector<int> ans(3, 0);
    forn(z,n/4) {
        // Me dejo solo la ultima palabra de cada linea
        forn(i,4) forn(j,m) cin>>v[i];
        // Reviso que las palabras sean validas
        if (v[0].size() < k or v[1].size() < k 
                or v[2].size() < k or v[3].size() < k) {
            continue;
        }

        ans[AABB] += aabb();
        ans[ABAB] += abab();
        ans[ABBA] += abba();
    }

    forn(i,3) cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}

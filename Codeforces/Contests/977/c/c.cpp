#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n, m, q; cin>>n>>m>>q;
        vector<ll> a(n), b(m);
        for(ll& x : a) cin>>x;
        for(ll& x : b) cin>>x; 

        int next = 0;
        set<int> roster;
        bool possible = true;
        for (int i = 0; i < m and possible; i++) {
            if (next < n and a[next] == b[i]) {
                next++;
                roster.insert(b[i]);
            } else if (not roster.empty() and roster.find(b[i]) != roster.end()) {

            } else {
                possible = false;
            }
        } 
        cout<<(possible ? "YA" : "TIDAK")<<"\n";
    }

    return 0;
}

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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        vector<int> v(n);
        vector<priority_queue<int>> q(n+1);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            q[v[i]].push(i);
        }

        int ans = 0;
        for (int x = n; x >= 1; x--) {
            while (!q[x].empty()) {
                int a = q[x].top(); q[x].pop();
                if (v[a] == 0) continue;
                ans++;
                for (int i = a; i < n and v[i] != 0; i++) {
                    v[i] = 0;
                }
            } 
        }

        cout<<ans<<"\n";
    }

    return 0;
}

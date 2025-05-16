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

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        deque<ll> v(n);
        for (ll& x : v) cin>>x;

        ll coins = 0, extra = 0;
        // Agarro todos los mases a la izq y menoses a la der
        while (!v.empty() and v.front() >= 0) {
            coins += v.front();
            v.pop_front();
        }
        while (!v.empty() and v.back() < 0) {
            coins += -v.back();
            v.pop_back();
        }
        
        if (!v.empty()) {
            // Lo mismo pero perdiendo gente
            n = v.size();
            vector<ll> mases(n,0), menoses(n,0);
            if (v[0] >= 0) mases[0] = v[0];
            if (v[n-1] < 0) menoses[n-1] = -v[n-1];
            for (int i = 1; i < n; i++) {
                mases[i] = mases[i-1] + (v[i] >= 0 ? v[i] : 0);
            }
            for (int i = n-2; i >= 0; i--) {
                menoses[i] = menoses[i+1] + (v[i] < 0 ? -v[i] : 0);
            }
            for (int i = 0; i < n; i++) {
                extra = max(extra, mases[i] + menoses[i]);
            }
        }

        cout<<coins+extra<<"\n";
    }

    return 0;
}

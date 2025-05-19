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

const int N = 15;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        int n, a, b; cin>>n>>a>>b;
        string s; cin>>s;

        vector<pair<int,int>> pts;
        int x = 0, y = 0;
        pts.push_back({0,0});
        for (char c : s) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'W') x--;
            else x++;
            pts.push_back({x,y});
        }

        bool found = false;
        pair<int,int> pivot = pts[pts.size()-1];
    
        for (auto& p : pts) {
            x = p.first, y = p.second;
            for (int k = 0; k <= 10 and !found; k++) {
                if (((pivot.first * k) + x) == a and ((pivot.second * k) + y) == b) {
                    found = true;
                    cout<<"YES\n";
                    break;
                }
            }
            if (found) break;
        }
        if (!found) cout<<"NO\n";
    }

    return 0;
}

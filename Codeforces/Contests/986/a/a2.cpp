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

        int x = 0, y = 0;
        int next = 0;
        bool found= false;
        for (int i = 0; i <= n*1000 and !found; i++) {
            char c = s[next];
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else x--;

            if (x == a and y == b) {
                found = true;
                cout<<"YES\n";
            }

            next++;
            next %= n;
        }

        if (!found) cout<<"NO\n";
    }

    return 0;
}

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

        bool found = false;
        int k = 0, ans = 0;

        // Pregunto por parejas
        // n-1 preguntas
        for (int i = 1; i+1 <= 2*n-2 and !found; i += 2) {
            cout<<"? "<<i<<" "<<(i+1)<<endl;
            cin>>ans;
            if (ans == -1) return 0;
            if (ans == 1) {
                found = true;
                k = i;
            }
        }
        
        if (found) {
            cout<<"! "<<k<<endl;
        } else {
            // Me quedan 2 preguntas
            cout<<"? "<<1<<" "<<2*n-1<<endl;
            cin>>ans;
            if (ans == -1) return 0;
            if (ans == 1) cout<<"! "<<1<<endl;
            else {
                cout<<"? "<<1<<" "<<2*n<<endl;
                cin>>ans;
                if (ans == -1) return 0;
                if (ans == 1) cout<<"! "<<1<<endl;
                else cout<<"! "<<2<<endl;
            }
        }
    }

    return 0;
}

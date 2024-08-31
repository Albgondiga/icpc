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

#define debug 0
#define ifd if (debug)

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string t; cin>>t;
    int n = t.size();

    vector<int> z = z_function(t);

    ifd for (auto i : z) cout<<i<<" ";
    ifd cout<<endl;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (z[i] > ans) {
            ifd cout<<"i = "<<i<<endl;
            ifd cout<<"z[i] = "<<z[i]<<endl;
            ifd cout<<"n-i = "<<n-i<<endl;
            // Overlap: i <= z[i]-1
            // Till the end: z[i] == n-i+1
            if ((i <= z[i]-1) && (z[i] == n-i)) {
                ans = z[i];
                break;
            }
        }
    }

    if (ans) {
        cout<<"YES\n";
        cout<<t.substr(0,ans)<<"\n";
    } else {
        cout<<"NO\n";
    }
    
    return 0;
}

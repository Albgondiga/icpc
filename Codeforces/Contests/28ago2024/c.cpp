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

vector<int> pi;

void prefixFunction(string s) {
    int n = (int)s.length();
    pi.assign(n,0);
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && (s[i] != s[j]))
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string t; cin>>t;
    int n = t.size();
    prefixFunction(t);

    ifd for (auto i : pi) cout<<i<<" ";
    ifd cout<<endl;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (pi[i] > ans) {
            if ((pi[i]-1 >= i-pi[i]+1))
                ans = pi[i];
        }
    }

    ifd cout<<ans<<endl;

    if (ans) {
        cout<<"YES\n";
        cout<<t.substr(0,ans)<<"\n";
    } else {
        cout<<"NO\n";
    }
    
    return 0;
}

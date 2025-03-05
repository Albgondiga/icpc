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

vector<int> prefix_function(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll kmp(string s, string t) {
    t = t + '#'; vector<int> pi = prefix_function(t);
    int n = s.length(), m = t.length();
    ll count = 0, prev = 0;
    forn(i,n) {
        ll l = prev;
        while (l > 0 and s[i] != s[l])
            l = pi[l-1];
        if (s[i] == t[l]) {
            l++;
            prev = l;
        }
        if (l == m) count++;
    }
    return count;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        string a, b; cin>>a>>b;
        cout<<kmp(b,a)<<"\n";
    }

    return 0;
}

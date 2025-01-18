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

#define debug 1
#define ifd if (debug)

vector<int> pF(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j]) 
            j++;
        pi[i] = j;
    }
    return pi;
}

bool check(ll m, ll maxPi, ll k, string& s) {
    ll count = k/maxPi;
    if (k % maxPi >= s.length()-maxPi) count++;
    if (count >= m) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        ll k; string s;
        cin>>k>>s;
        if (k == -1) return 0;

        if (s.length() > k){
            cout<<0<<'\n';
        } else {
            vector<int> pi = pF(s);
            auto it = upper_bound(pi.begin(), pi.end(), 0);
            if (it == pi.end()) {
                cout<<k/s.length()<<'\n';
            } else {
                ll maxP = *upper_bound(pi.begin(), pi.end(), 0);
                ifd cout<<"maxP: "<<maxP<<'\n';
                ll length = s.length()-maxP;
                ll count = k/length;
                cout<<count<<'\n';
            }
        }

        // // ll l = 1, r = k, ans = 0;
        // // while (l <= r) {
        // //     ll m = l+(r-l)/2;
        // //     if (check(m, maxP, k, s)) {
        // //         ans = m;
        // //         l = m+1;
        // //     } else {
        // //         r = m-1;
        // //     }
        // // }
    }

    return 0;
}

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
 
vector<int> manacher_odd(string& s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        if(i <= r) {
            p[i] = min(r - i, p[l + (r - i)]);
        }
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
 
vector<int> manacher(string& s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    t.push_back('#');
    auto res = manacher_odd(t);
    return vector<int>(begin(res) + 1, end(res) - 1);
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    string s; cin>>s;
 
    auto p = manacher(s);
 
    int best = max_element(begin(p), end(p)) - begin(p);
    int len   = p[best] - 1;
    int start = (best + 1 - len) / 2;
    
    string ans = s.substr(start, len);
    cout<<ans<<"\n";
 
    return 0;
}
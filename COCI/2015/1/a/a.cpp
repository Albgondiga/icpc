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

#define P 0
#define K 1
#define H 2
#define T 3

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin>>s;

    vector<vector<int>> v(4, vector<int>(14,0));
    int i = 0;
    while (i < s.size()) {
        int letra = -1;
        char c = s[i];
        if (c == 'P') letra = P;
        else if (c == 'K') letra = K;
        else if (c == 'H') letra = H;
        else if (c == 'T') letra = T;

        int val = 0;
        val += (s[i+1]-'0')*10;
        val += (s[i+2]-'0');

        v[letra][val]++;

        i += 3;
    }

    vector<int> ans(4,0);

    forn(i,4) forr(j, 1, 14) {
        if (v[i][j] > 1) {
            cout<<"GRESKA\n";
            return 0;
        } else if (v[i][j] == 0) {
            ans[i]++;
        }
    }

    for (int x : ans) cout<<x<<" ";

    return 0;
}

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
        ll a, b, c, m; cin>>a>>b>>c>>m;
        ll ab = (a*b)/gcd(a,b), ac = (a*c)/gcd(a,c), bc = (b*c)/gcd(b,c)
            , abc = (ab*c)/gcd(ab,c);

        //cout<<":) "<<m/a<<" "<<m/b<<" "<<m/c<<" "<<endl;
        //cout<<":) "<<m/ab<<" "<<m/ac<<" "<<m/bc<<" "<<m/abc<<endl;
        ll ansA = 6*(m/a-m/ab-m/ac+m/abc)+3*(m/ab-m/abc + m/ac-m/abc)+2*(m/abc);
        ll ansB = 6*(m/b-m/ab-m/bc+m/abc)+3*(m/ab-m/abc + m/bc-m/abc)+2*(m/abc);
        ll ansC = 6*(m/c-m/ac-m/bc+m/abc)+3*(m/ac-m/abc + m/bc-m/abc)+2*(m/abc);

        cout<<ansA<<" "<<ansB<<" "<<ansC<<"\n";
    }

    return 0;
}

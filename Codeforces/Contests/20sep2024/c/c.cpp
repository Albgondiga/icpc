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

int ask(const string& q) {
    cout<<"? "<<q<<endl;
    int x; cin>>x;
    return x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    int n;
    while (t--) {
        cin>>n;
        string password = "", q = "";
        int ans0, ans1;
        while (password.size() < n) {
            if (ask(password+'0')) {
                password += '0';
            } else if (ask(password+'1')) {
                password += '1';
            } else {
                break;
            }
        }
        while (password.size() < n) {
            if (ask('0'+password)) {
                password = '0'+password;
            } else {
                password = '1'+password;
            }
        }
        cout<<"! "<<password<<endl;
    }

    return 0;
}

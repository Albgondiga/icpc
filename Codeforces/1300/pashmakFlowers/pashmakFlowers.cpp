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
const int MAXN=100100;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

ll n;
vector<ll> b;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    b.resize(n);
    map<ll,ll> freq;
    forn(i,n) { 
        cin>>b[i];
        freq[b[i]]++;
    }

    if (n == 2) {
        cout<<abs(b[0]-b[1])<<" "<<1<<"\n";
        return 0;
    }

    sort(b.begin(), b.end());

    ll diff = b[n-1]-b[0];
    ll count = freq[b[0]] * freq[b[n-1]];
    if (b[0] == b[n-1]) count = n*(n-1)/2;

    cout<<diff<<" "<<count<<"\n";

    return 0;
}
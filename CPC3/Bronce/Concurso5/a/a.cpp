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

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t; cin>>t;
    forn(i,t) {
        ll m; cin>>m;
        // n(n-1)/2 >= M
        ll low = 1; ll high = 2*m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
        
            if (mid*(mid-1)/2 == m) {
                cout<<mid<<"\n";
                break;
            }
            if (mid*(mid-1)/2 < m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout<<low<<"\n";
    }
    return 0;
}
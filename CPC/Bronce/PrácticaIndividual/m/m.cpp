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

#define debug 0
#define ifd if (debug)

#define right 1
#define left -1

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];
    sort(a.begin(),a.end());

    ll i = n/2;
    ll dir = right;
    forn(j,k) {
        ifd cout<<"i="<<i<<endl;
        if (dir == right && i == a.size()-1) {
            a[i]++;
            i = n/2;
        } else if (dir == left && i == n/2) {
            a[i]++;
            dir = right;
        } else if (dir == right) {
            a[i]++;
            if (a[i] > a[i+1])
                i++;
        } else if (dir == left) {
            a[i]++;
            if (a[i] > a[i-1])
                i--;
        }
    }
    sort(a.begin(),a.end());
    ifd cout<<"i="<<i<<endl;
    cout<<a[n/2]<<"\n";
}
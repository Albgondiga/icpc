#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> st(n);
    vector<ll> sums(n,0);
    forn(i,n) {
        cin>>st[i];
    }
    sums[0] = st[0];
    for(int i = 1; i < n; i++) {
        sums[i] = sums[i-1]+st[i];
        ifd cout<<"sums[i]="<<sums[i]<<endl;
    }
    ll count = 0;
    for(int i = 0; i < n-1; i++) {
        if (sums[i] == sums[n-1]-sums[i])
            count++;
    }
    cout<<count<<endl;
    return 0;
}
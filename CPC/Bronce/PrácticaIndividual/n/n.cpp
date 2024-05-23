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

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, x; cin>>n>>x;
    vector<ll> a(n), b(n);
    forn(i,n) cin >> a[i], b[i] = a[i];

    sort(b.begin(),b.end());
    ll i = 0;
    ll j = n-1;
    while (i <= j) {
        if (b[j] == x-b[i]) {
            ifd cout<<b[i]<<"+"<<b[j]<<"\n";
            cout<<find(a.begin(),a.end(),b[i])-a.begin()+1
            <<" "<<find(a.begin(),a.end(),b[j])-a.begin()+1<<"\n";
            return 0;
        } else {
            if (b[j] > x-b[i]) {
                j--;
            } else {
                i++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}
// 
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
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> v(n);
    forn(i,n) cin>>v[i];

    bool todos0 = true;
    forn(i,n) {
        if (v[i] != 0) {
            todos0 = false;
            break;
        }
     }

    if (todos0) {
        cout<<0<<"\n";
    } else {
        ll count = 1;
        bool creciente = true;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i-1] && !creciente) {
                count++;
                creciente = 1;
            } else if (v[i] < v[i-1]) {
                creciente = 0;
            }
        }

        cout<<count<<"\n";
    }

    return 0;
}
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

    ll n, m; cin>>n>>m;
    set<ll> s;
    vector<ll> freq(m+1);
    ll x, repetidos = 0; 
    forn(i,n) {
        cin>>x;
        s.insert(x);
        if (freq[x] == 1) repetidos++;
        freq[x]++;
    }

    if (s.size() < m) {
        if (s.size() >= 4) {
            cout<<m<<"\n";
        } else {
            if (s.size() == 3) {
                if (m >= 5) {
                    cout<<m<<"\n";
                } else { // m == 4
                    if (repetidos == 0) cout<<m-1<<"\n";
                    else cout<<m<<"\n";
                }
            } else if (s.size() == 2) {
                if (repetidos == 0) cout<<m-2<<"\n";
                else if (repetidos == 1) cout<<m-1<<"\n";
                else cout<<m<<"\n"; // repetidos == 2
            } else { // s.size() == 1
                cout<<1<<"\n";
            }
        }
    } else { // s.size() == m
        if (m == 1) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}

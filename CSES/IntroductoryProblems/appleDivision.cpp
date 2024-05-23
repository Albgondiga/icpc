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
typedef pair<ll, ll> pll;
#define mp make_pair 
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1

ll sumApple(vector<ll>& w, size_t next, ll g1, ll g2) {
    if (next == w.size()) 
        return abs(g1-g2);

    ll toG1 = sumApple(w, next+1, g1+w[next], g2);
    ll toG2 = sumApple(w, next+1, g1, g2+w[next]);

    return min(toG1, toG2);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> w;
    forn(i,n) {
        ll x;
        cin>>x;
        w.push_back(x);
    }
    cout<<sumApple(w,0,0,0)<<endl;
    return 0;
}

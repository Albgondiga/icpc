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
const int MOD =1000000007;

const int exponente =1000000005;

ll exp(ll b, ll e) {
    ll r =1;
    while (e) {
        if (e%2) r=(r*b)%MOD;
        b=(b*b)%MOD;
        e/=2;
    }

    return r;
}


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m; cin>>n>>m;
    vector<ll> guess(n);
    vector<ll> guesses(n);
    ll top, time;
    forn(i, m) {
        cin>>top>>time;
        top--;
        guess[top]+=time;
        guesses[top]++;
    }

    ll total=0;
    forn(i, n) {
        if(guess[i]%guesses[i]==0) {
            total+=guess[i]/guesses[i];
            continue;
        }
        ll num =guess[i];
        ll denum=exp(guesses[i], exponente);
        total+=((num*denum)%MOD);
        total%=MOD;
    }

    cout<<total<<"\n";


}

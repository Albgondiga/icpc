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

    ll n; cin>>n;
    ll k = 0;
    vector<bool> prime(n+2,true);
    vector<ll> color(n+2);
    prime[0]=prime[1]=false;
    for (int i = 2; i*i <= n+1; i++) {
        if (prime[i]) {
            for (int j=i*i; j <= n+1; j+=i)
                prime[j]=false;
        }
    }
    if (n >= 3) {
        cout<<2<<"\n";
    } else {
        cout<<1<<"\n";
    }
    for (int i = 2; i<n+2; i++) {
        if (prime[i]) {
            cout<<1<<" ";
        } else {
            cout<<2<<" ";
        }
    }
    cout<<endl;
}
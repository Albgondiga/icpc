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
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

vector<ll> sieve(ll n) {
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (ll i = 2; i*i <= n; i++) {
        if (prime[i]) {
            for (ll j=i*i; j <= n; j+=i)
                prime[j]=false;
        }
    }
    vector<ll> primes;
    for (ll i = 2; i*i <= n; i++) {
        if (prime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;

    vector<ll> primes = sieve(n);
    for (ll i = 0; i < primes.size(); i++) {
        bool d = false;
        while (n % primes[i] == 0) {
            d = true;
            n/=primes[i];
        }
        if (d) cout<<primes[i]<<"\n";
    }
}
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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

const int MAX = 1e6+1;
bool isPrime[MAX];
 
void primes() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p*p < MAX; p++) {
        if (isPrime[p] == true) {
            for (int i = p*p; i < MAX; i += p)
                isPrime[i] = false;
        }
    }
}

ll raizQ(ll a) {
    ll x = sqrt(a) + 2;
    while (x * x > a) x--;
    return x;
}

string check(ll x) {
    ll raiz = raizQ(x);
    ifd cout<<"raiz="<<raiz<<endl;
    if (raiz*raiz == x) {
        if (isPrime[raiz]) return "YES";
    }
    return "NO";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> v(n);
    forn(i,n) cin>>v[i];

    primes();
    forn(i,n) cout<<check(v[i])<<"\n";

    return 0;
}
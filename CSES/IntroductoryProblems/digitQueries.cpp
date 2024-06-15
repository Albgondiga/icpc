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
const int MAXn=100100;

#define MOD 100000007

#define debug 0
#define ifd if (debug)

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return binpow(a,b-1) * a;
    ll res = binpow(a,b/2);
    return res * res;
}

int main() {
    // Example 1
    ll q; cin >> q;
    forn (i, q) {
        ll k; cin >> k;

        // No of digits
        ll digits = 1;
        // Total numbers in current digit interval
        ll base = 9;

        // Find the interval in which the Nth digit lies
        while (k - digits * base > 0) {
            k -= digits * base;
            base *= 10;
            digits++;
        }
        ll index = k % digits;

        // Calculate the number which contains the kth digit
        ll res = binpow(10, (digits - 1)) + (k - 1) / digits;

        // Find out which digit in the number is the result
        if (index != 0)
            res = res / binpow(10, digits - index);

        cout<<res%10<<"\n";
    }
    return 0;
}
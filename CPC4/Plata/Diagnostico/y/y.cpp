#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0) {
    ll g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

bool valid(ll x) {
    return x >= -1e18 and x <= 1e18;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll A,B,X,Y; cin>>X>>Y;
    // Shoelace: |AY-BX| = 2
    // AY-BX = 2
    if (find_any_solution(Y, -X, 2, A, B)) {
        if (valid(A) and valid(B)) {
            cout<<A<<" "<<B<<"\n";
            return 0;
        }
    }
    // -AY+BX = 2
    if (find_any_solution(-Y, X, 2, A, B)) {
        if (valid(A) and valid(B)) {
            cout<<A<<" "<<B<<"\n";
            return 0;
        }
    }

    cout<<-1<<"\n";
    return 0;
}

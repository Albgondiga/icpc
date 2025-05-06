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

const int N = 2e5+5;
int n, k;
vector<int> v(N);

bool primerosDos() {
    vector<int> s(n), maxMedio(n);
    s[0] = v[0];
    for (int i = 1; i < n; i++) {
        s[i] = v[i] + s[i-1];
    }
    maxMedio[n-1] = -1;
    maxMedio[n-2] = s[n-2];
    for (int i = n-3; i >= 0; i--) {
        maxMedio[i] = max(maxMedio[i+1], s[i]);
    }

    int i = 0;
    while (i < n-2) {
        if (s[i] < 0) {
            i++;
            continue;
        }
        if (maxMedio[i+1] >= s[i]) {
            return true;
        }
        i++;
    }
    return false;
}

bool primeroYultimo() {
    int i = 0, j = n-1;
    int s = 0;
    while (i < n) {
        s += v[i];
        if (s >= 0) break;
        i++;
    }
    s = 0;
    while (j > 0) {
        s += v[j];
        if (s >= 0) break;
        j--;
    }
    if (i+1<j) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        cin>>n>>k;

        for (int i = 0; i < n; i++) {
            int x; cin>>x;
            if (x > k) v[i] = -1;
            v[i] = 1;
        }

        // Para ganar necesito al menos dos intervalos
        // con mediana <= k
        if (primerosDos() or primeroYultimo()) {
            cout<<"YES\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            swap(v[i],v[n-1-i]);
        }
        if (primerosDos()) {
            cout<<"YES\n";
            continue;
        }

        cout<<"NO\n";
    }

    return 0;
}

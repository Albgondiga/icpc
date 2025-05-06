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
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<int> v(N), s(N,0);
    for (int i = 1; i <= n; i++) {
        cin>>v[i];
        s[i] = s[i-1]+v[i];
    }

    vector<pair<int,int>> bloques(k+1);
    vector<ll> sumaBloque(k+1,0);
    int tam = n/k;
    int l = 1, r = tam;
    for (int i = 1; i <= k; i++) {
        bloques[i] = {l,min(r,k)};
        sumaBloque[i] = s[r]-s[l-1]; 
    }

    while(true) {
        bool seguir = true;
        for (int b = 1; b <= k-1; b++) {
            int i = bloques[b].first, j = bloques[b].second;
            if (sumaBloque[b-1]+v[i] <= sumaBloque[b] and i != j) {
                sumaBloque[b-1] += v[i];
                sumaBloque[b] -= v[i];
                bloques[b-1].second = i;
                bloques[b].first = i+1;
            }
            if (sumaBloque[b+1]+v[j] <= sumaBloque[b] and i != j) {
                sumaBloque[b+1] += v[i];
                sumaBloque[b] -= v[i];
                bloques[b+1].second = i;
                bloques[b].first = i+1;
            }
        }
    }

    return 0;
}

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

const int N = 1e5+5;
int link[N], tamano[N];

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (tamano[a] < tamano[b]) swap(a,b);
    tamano[a] += tamano[b];
    link[b] = a;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        link[i] = i;
        tamano[i] = 1;
    }

    while (m--) {
        string s; int u, v;
        cin>>s>>u>>v;
        if (s[0] == 'u') {
            if (!same(u,v)) unite(u,v);
        } else {
            if (same(u,v)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}

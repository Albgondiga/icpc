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

// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B

const int N = 3e5+5;

int link[N], tamano[N], m[N], M[N];

int find(int a) {
  return link[a] = (link[a] == a ? a : find(link[a]));
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (tamano[a] < tamano[b]) swap(a,b);
    tamano[a] += tamano[b];
    m[a] = min(m[a],m[b]);
    M[a] = max(M[a],M[b]);
    link[b] = a;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, q; cin>>n>>q;

    for (int i = 1; i <= n; i++) {
        m[i] = M[i] = link[i] = i;
        tamano[i] = 1;
    }

    while (q--) {
        string s; int u, v;
        cin>>s>>u;
        if (s[0] == 'u') {
            cin>>v;
            if (!same(u,v)) unite(u,v);
        } else {
            int p = find(u);
            cout<<m[p]<<" "<<M[p]<<" "<<tamano[p]<<"\n";
        }
    }

    return 0;
}

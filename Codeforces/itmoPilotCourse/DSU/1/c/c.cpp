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

const int N = 2e5+5;

int link[N], r[N], pts[N], sumar[N];

int find(int a) {
    if (link[a] != a) {
        link[a] = find(link[a]);
    }
    return link[a];
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    if (!same(a,b)) {
        a = find(a), b = find(b);
        if (r[a] == r[b]) {
            r[a]++;
        }
        if (r[a] > r[b]) {
            link[b] = a;
        } else {
            link[a] = b;
        }
    }
}

void add(int a, int v) {
    sumar[link[a]] += v;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, q; cin>>n>>q;

    for (int i = 1; i <= n; i++) {
        link[i] = i;
        r[i] = pts[i] = sumar[i] = 0;
    }

    while (q--) {
        string s; int u, v;
        cin>>s>>u;
        if (s[0] == 'u') {
            cin>>v;
            if (!same(u,v)) unite(u,v);
        } else if (s[0] == 'a') {
            cin>>v;

        } else {
            int p = find(u);

        }
    }

    return 0;
}

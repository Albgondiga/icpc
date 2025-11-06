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

// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

const int N = 50005;

int link[N], tamano[N];

int find(int a) {
  return link[a] = (link[a] == a ? a : find(link[a]));
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    if (!same(a,b)) {
        a = find(a), b = find(b);
        if (tamano[a] < tamano[b]) swap(a,b);
        tamano[a] += tamano[b];
        link[b] = a;
    }
}

map<pair<int,int>, bool> petar;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, q; cin>>n>>m>>q;

    for (int i = 1; i <= n; i++) {
        link[i] = i;
        tamano[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin>>u>>v;
    }
    stack<tuple<string,int,int>> ops;
    for (int i = 1; i <= q; i++) {
        string s; int u, v; cin>>s>>u>>v;
        ops.push({s,u,v});
        petar[{u,v}] = true;
    }
    stack<string> ans;
    while (!ops.empty()) {
        string s; int u, v;
        tie(s,u,v) = ops.top(); ops.pop();
        if (s[0] == 'a') {
            if (same(u,v)) ans.push("YES\n");
            else ans.push("NO\n");
        } else {
            unite(u,v);
        }
    }
    while (!ans.empty()) {
        cout<<ans.top(); ans.pop();
    }
    return 0;
}

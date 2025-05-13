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

// https://acm.timus.ru/problem.aspx?space=1&num=1671

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

int n, m, q;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        link[i] = i;
        tamano[i] = 1;
    }

    vector<pair<int,int>> edges;
    for (int i = 1; i <= m; i++) {
        int a, b; cin>>a>>b;
        edges.push_back({a,b});
    }
    
    cin>>q;
    vector<bool> petar(m+1, false);
    vector<int> petados;
    for (int i = 1; i <= q; i++) {
        int x; cin>>x;
        petar[x] = true;
        petados.push_back(x);
    }

    for (int i = 1; i <= m; i++) {
        if (petar[i]) continue;
        int a = edges[i-1].first, b = edges[i-1].second;
        if (!same(a,b)) unite(a,b);
    }
    
    set<int> papas;
    for (int i = 1; i <= n; i++) {
        papas.insert(find(i));
    }

    int count = papas.size();
    vector<int> ans;
    ans.push_back(count);
    for (int i = petados.size()-1; i >= 1; i--) {
        int a = edges[petados[i]-1].first, b = edges[petados[i]-1].second;
        if (same(a,b)) {
            ans.push_back(count);
        } else {
            unite(a,b);
            ans.push_back(--count);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int& x : ans) cout<<x<<" ";
    cout<<"\n";

    return 0;
}

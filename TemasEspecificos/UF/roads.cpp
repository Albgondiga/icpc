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

// https://codeforces.com/contest/25/problem/D

const int N = 1005;
int link[N], tamano[N];

int n;

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

    cin>>n;

    for (int i = 1; i <= n; i++) {
        link[i] = i;
        tamano[i] = 1;
    }

    vector<pair<int,int>> repetidos, nuevos;

    for (int i = 1; i <= n-1; i++) {
        int a, b; cin>>a>>b;
        if (same(a,b)) {
            repetidos.push_back({a,b});
            continue;
        }
        unite(a,b);
    }

    if (repetidos.size() == 0) {
        cout<<0<<"\n";
        return 0;
    }

    int base = find(1);
    for (int i = 2; i <= n; i++) {
        if (same(base, find(i))) continue;
        nuevos.push_back({base, i});
        unite(base,i);
    }

    cout<<repetidos.size()<<"\n";
    for (int i = 0; i < repetidos.size(); i++) {
        cout<<repetidos[i].first<<" "<<repetidos[i].second<<" ";
        cout<<nuevos[i].first<<" "<<nuevos[i].second<<"\n";
    }

    return 0;
}

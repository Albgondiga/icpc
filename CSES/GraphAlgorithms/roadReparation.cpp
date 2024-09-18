#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 1e5+1;
int n, m;
vector<tuple<ll,int,int>> edges;

int Link[N];
int Size[N];

int find(int x) {
    while (x != Link[x]) x = Link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

int unite(int a, int b) {
    a = find(a); b = find(b);
    if (Size[a] < Size[b]) swap(a,b);
    Size[a] += Size[b];
    Link[b] = a;
    return Size[a];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    int a, b; ll c;
    forn(i,m) {
        cin>>a>>b>>c;
        edges.push_back({c,a,b});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) Link[i] = i;
    for (int i = 1; i <= n; i++) Size[i] = 1;

    ll cost = 0;
    int count = n;
    for (auto e : edges) {
        tie(c,a,b) = e;
        if (!same(a,b)) {
            cost += c;
            count--;
            unite(a,b);
        }
    }

    if (count == 1) cout<<cost<<"\n";
    else cout<<"IMPOSSIBLE\n";

    return 0;
}

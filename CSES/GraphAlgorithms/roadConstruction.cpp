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
int Link[N];
int Size[N];
int n, m;

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

    for (int i = 1; i <= n; i++) Link[i] = i;
    for (int i = 1; i <= n; i++) Size[i] = 1;

    int count = n; 
    int maxSize = 1;
    forn (i,m) {
        int a, b; cin>>a>>b;
        if (!same(a,b)) {
            count--;
            maxSize = max(maxSize, unite(a,b));
        }
        cout<<count<<" "<<maxSize<<"\n";
    }

    return 0;
}

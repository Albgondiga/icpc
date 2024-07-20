// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1

ll n, m, q; 
 
pair<ll,ll> mapeamiento(ll a, ll b, ll k) { 
    ll i = b-a; 
    ll l = i*n - i*(i+1)/2+a; 
    ll r = l+k-1; 
    return {l,r}; 
} 
 

vector<ll> make(vector<ll> ar) {
    vector<ll> tree=ar;
    for(int i=1; i<tree.size(); i++) {
        int p=i+(i&-i);
        if (p<tree.size()) {
            tree[p]=tree[p]+tree[i];
        }
    }
    return tree;
}

void add(int i, int k, vector<ll>& tree) {
    if (i<0) return;
    while (i<tree.size()) {
        tree[i]+=k;
        i+=i&-i;

    }
}

int sum(int i, vector<ll> & tree) {
    int sum=0;
    while(i>0) {
        sum+=tree[i];
        i-=i&-i;
    }
    return sum;
}

int main() { 
 
    cin.tie(0); 
    ios_base::sync_with_stdio(false); 
 
    cin>>n>>m>>q; 
 
    vector<ll> ar(n*(n+1)/2+1, 0); 
    vector<ll> tree=make(ar);
 
    while(m--) { 
        ll a, b, k; cin>>a>>b>>k;
        pair<ll,ll> p = mapeamiento(a,b,k); 
        add(p.second+1, 1, tree);
        add(p.first, -1, tree);
    }

    while (q--) {
        ll a, b;
        cin>>a>>b;
        pair<ll, ll> p = mapeamiento(a, b, 1);
        int target=p.first;
        int v1=sum(target, tree);
        int v2=sum(target-1, tree);
        int v3=v1-v2;
        cout<<v3%2<<endl;
    }
 
 
}

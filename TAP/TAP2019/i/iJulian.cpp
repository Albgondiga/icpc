
#include <bits/stdc++.h>
 
using namespace std;
 
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define pb push_back
using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;
using vpi = vector<pi>;
 
const int N = 1e4;
vpi dp[N];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m,q;
    cin>>n>>m>>q;
    while(m--){
        int k,a,b;
        cin>>k>>a>>b;
        dp[b-a].pb({a,-1});
        dp[b-a].pb({a+k,-1});
    }
 
    F0(i,q){
        int a,b;
        cin>>a>>b;
        if(a > b) swap(a,b);
        dp[b-a].pb({a,i});
    }
 
    vi res(q);
    F0(i,n){
        sort(dp[i].begin(),dp[i].end());
        bool coso = false;
        for(auto [_,b] : dp[i]){
            if(b == -1) coso = !coso;
            else res[b] = coso;
        }
    }

    for(auto x : res) cout<<(x? "SI\n" : "NO\n");
 
    return 0;
}

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9;
const ll mxX = 1e6+5;
ll n, x;
vector<ll> coins;
ll dp[mxX];
ll num[mxX];
ll seen[mxX], seen2[mxX];
ll first[mxX];

ll num_ways(ll x){
    if( x == 0) return 1;

    if(seen2[x]) return num[x];

    ll res = 0;
    for(auto c : coins){
        if(x-c >= 0){
            res += num_ways(x-c);

        }
    }
    seen2[x] = 1;
    return num[x] = res;
}


ll solve(ll x){
    if( x == 0) return 0;

    if(seen[x]) return dp[x];

    ll res = INF;
    for(auto c : coins){
        if(x-c >= 0){
            ll new_res = solve(x-c) + 1;
            if(new_res < res){
                res = new_res;
                first[x] = c;
            }
        }
    }
    seen[x] = 1;
    return dp[x] = res;
}

int main(){
    memset(seen,0, sizeof(seen));
    memset(seen2,0, sizeof(seen2));

    cin>>n;
    coins.resize(n);
    for(int i = 0;i<n;i++){
        cin>>coins[i];
    }
    cin>>x;
    cout<<solve(x)<<endl;
    cout<<num_ways(x)<<"\n";

    while(x != 0){
        cout<< first[x]<<" ";
        x = x-first[x];
    }
    cout<<"\n";
}

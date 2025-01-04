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

#define debug 0
#define ifd if (debug)


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > subm (n, vector<ll> (m));
    vector<vector<bool> > solved(n, vector<bool> (m));
    ll q; cin>>q;
    while (q--) {
        ll id, p; string res;
        cin>>id>>p>>res;
        id--; p--;
        subm[id][p]++;
        if (res=="AC") {
            solved[id][p]=true;
            subm[id][p]--;
        }
    }
    forn(i, n) forn(j,m) if (!solved[i][j]) subm[i][j]=0;
    ifd {
        cout<<"solucionados:"<<endl;

        forn(i, n) {
            forn(j, m) {
                cout<<subm[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<ll>> pSum(n, vector<ll> (m));
    forn(i, n) {
        forn(j, m) {
            pSum[i][j]=subm[i][j];
            if (i>0) pSum[i][j] +=pSum[i-1][j];
            if (j>0) pSum[i][j] +=pSum[i][j-1];
            if (i>0&&j>0) pSum[i][j]-=pSum[i-1][j-1];
        }
    }
    ifd {
        cout<<"pSum:"<<endl;
        forn(i, n) {
            forn(j, m) {
                cout<<pSum[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    ll id1, id2, p1, p2;
    cin>>q;
    while (q--) {
        cin>>id1>>p1>>id2>>p2;
        id1--; id2--; p1--; p2--;
        ll ans = pSum[id2][p2];
        if (id1==0&&p1==0) {
            cout<<ans<<endl;
            continue;
        }
        if (id1 == 0) {
            ans-=pSum[id2][p1-1];
            cout<<ans<<endl;
            continue;
        }
        if (p1==0) {
            ans-=pSum[id1-1][p2];
            cout<<ans<<endl;
            continue;
        }
        ans=ans-pSum[id1-1][p2]-pSum[id2][p1-1] +pSum[id1-1][p1-1];
        cout<<ans<<endl;
            

        
        // cout<<pSum[id1][<<endl;
    }
}
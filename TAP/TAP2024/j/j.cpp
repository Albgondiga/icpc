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
int numMitades=1;
vector<int> res;
int mitades=0;
bool esPar=false;
ll x;

void hagaMedios() {
    if (!x%2) return;
    if (mitades>numMitades) {
        res.push_back(x/2);
        mitades--;
    }
}

bool rComp(ll a, ll b) {
    return a>b;
}






int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k; cin>>n>>x;
    vector<ll> vA, vB;
    set<ll> a, b;
    for (int i=0; i<n; i++) {
        cin>>k;
        if ((x%2==0)&&(k==x/2)) {
            mitades++;
            continue;
        }
        if (a.empty()||(a.find(x-k)==a.end())) {
            a.insert(k);
            vA.push_back(k);
            continue;
        }

        b.insert(k);
        vB.push_back(k);
    }

    sort(vA.begin(), vA.end());
    sort(vB.begin(), vB.end());
    
    bool error=false;
    int nA=vA.size(), nB=vB.size();
    if (!vB.empty()&&vA[nA-1]==x-vB[0]) {
        sort(vB.begin(), vB.end(), rComp);
        if (vA[nA-1]==x-vB[0]) {
            sort(vA.begin(), vA.end(), rComp);
            if (vA[nA-1]==x-vB[0]) {
                sort(vB.begin(), vB.end());
                if (vA[nA-1]==x-vB[0]) error=true;
            }
        }
    }
    if (error) {
        cout<<"*\n";
        return 0;
    }
    ifd {
        cout<<"vB se ve: "<<endl;
        for (auto u:vB) cout<<u<<" ";
        cout<<endl;
    }
    for (ll u:vA) {
        hagaMedios();
        res.push_back(u);
    }
    numMitades=0;
    hagaMedios();
    ifd {
        cout<<"ya vacié A, res se ve:"<<endl;
        for(auto u:res) cout<<u<<" ";
        cout<<endl;
    }
    ll last=res[res.size()-1];
    if (!vB.empty()&&vB[0]==(x-last)) error=1;
    for (ll u:vB) {
        res.push_back(u);
        hagaMedios();
    }

    if (mitades) error=true;

    if (error) {
        ifd cout<<"aaaaaa"<<endl;
        cout<<"*\n";
    }

    else {
        for (ll u:res) cout<<u<<" ";
        cout<<"\n";
    }

}

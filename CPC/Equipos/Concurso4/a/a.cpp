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
#define ifd if (debug)
map<string, int> id;
map<string, bool> seen;

vector<vector<int> > adj;
vector<bool> vistoLocal;
vector<bool> vistoGlobal;

bool ciclo (int x) {
    bool ans=0;
    vistoLocal[x]=true;
    vistoGlobal[x]=true;
    for (auto u:adj[x]) {
        if (vistoLocal[u]) {
            ans=1;
            break;
        }
        if (vistoGlobal[u]) continue;
        ans|=ciclo(u);
        if (ans) break;
    }
    vistoLocal[x]=false;
    return ans;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int indx=0; 
    vistoLocal.resize(2*n+1);
    vistoGlobal.resize(2*n+1);

    adj.resize(2*n+1);
    forn(i,n) {
        string a, b;
        cin>>a>>b;
        int idA, idB;
        if (seen[a]) idA=id[a];
        else {
            seen[a]=true;
            idA=indx++;
            id[a]=idA;
        }

        if (seen[b]) idB=id[b];
        else {
            seen[b]=true;
            idB=indx++;
            id[b]=idB;
        }

        adj[idA].push_back(idB);
        
    }
    int ans=0;
    for (int i =0; i<(indx+1)&&!ans; i++) {
        //vistoLocal.resize(2*n+1);
        if (vistoGlobal[i]) continue;
        forn(i, 2*n+1) vistoLocal[i]=0;
        ans |= ciclo(i);
    }
    if (!ans) cout<<"I disagree with the advisor\n";
    else cout<<"No more comedians++\n";
}

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



int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    string s; cin>>s;
    vector<int> ultAct(n+1);

    ii global=make_pair(-2, -1);
    int q; cin>>q;
    int t, x;
    char c;
    for (int i=1; i<=q; i++) {
        if (debug) cout<<"query #"<<q<<endl;
        cin>>t>>x>>c;
        if (debug) cout<<"leí t="<<t<<endl;
        x--;
        if (t==1) {
            if (debug) cout<<"s["<<x<<"]="<<c<<endl;
            s[x]=c;
            ultAct[x]=i;
        }
        else if (t==2) {
            if (debug) cout<<"todas pasan a minúsculas!"<<endl;
            global.first=0;
            global.second=i;
        }
        else {
            if (debug) cout<<"todas pasan a mayúsculas!"<<endl;
            global.first=1;
            global.second=i;
        }
        
    }

    if (global.first==-2) cout<<s<<endl;

    else {
        forn(i, n) {
            if (ultAct[i]<global.second) {
                if (global.first==0) s[i]=tolower(s[i]);
                else s[i]=toupper(s[i]);
            }
        }
        cout<<s<<endl;
    }

    

}

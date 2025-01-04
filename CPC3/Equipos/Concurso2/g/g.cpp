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


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;

    
    int i1=1, i2=n, i3;
    while(i1!=i2-1) {
        i3=(i2-i1)/2 +i1;
        cout<<"? "<<i3<<endl;
        int res; cin>>res;
        if (res==0) i1=i3;
        else i2=i3;
    }
    cout<<"! "<<i1<<endl;
    return 0;
}   

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
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    deque<int> dq;
    int t;
    cin>>t;
    forn(i,t) {
        //if(i>0) cout<<"\n";
        dq.clear();
        cout<<"Case "<<i+1<<":\n";
        int n,m;
        cin>>n>>m;
        forn(j,m) {
            string s;
            cin >> s;
            ifd cout<<"j = "<<j<<endl;
            ifd cout<<"s = "<<s<<endl;
            if (s == "pushLeft") {
                int x;
                cin>>x;
                if (dq.size() == n) {
                    cout<<"The queue is full"<<"\n";
                } else {
                    dq.push_front(x);
                    cout<<"Pushed in left: "<<x<<"\n";
                }
            } else if (s == "pushRight") {
                int x;
                cin>>x;
                if (dq.size() == n) {
                    cout<<"The queue is full"<<"\n";
                } else {
                    dq.push_back(x);
                    cout<<"Pushed in right: "<<x<<"\n";
                }
            } else if (s == "popLeft") {
                if (dq.size() == 0) {
                    cout<<"The queue is empty"<<"\n";
                } else {
                    int x = dq.front();
                    dq.pop_front();
                    cout<<"Popped from left: "<<x<<"\n";
                    ifd cout<<"size="<<dq.size()<<endl;
                }
            } else if (s == "popRight") {
                if (dq.size() == 0) {
                    cout<<"The queue is empty"<<"\n";
                } else {
                    int x = dq.back();
                    dq.pop_back();
                    cout<<"Popped from right: "<<x<<"\n";
                }
            }
        }
    }
}
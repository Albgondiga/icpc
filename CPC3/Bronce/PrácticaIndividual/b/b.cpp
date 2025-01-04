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
typedef pair<string,int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll time = 0;
    queue<si> q;
    int n, qt;
    cin>>n>>qt;
    forn(i,n) {
        string name;
        int time;
        cin>>name>>time;
        q.push(make_pair(name,time));
    }
    while(!q.empty()) {
        int t = q.front().second;
        string name = q.front().first;
        if (t <= qt) {
            time += t;
            cout<<name<<" "<<time<<"\n";
        } else {
            time += qt;
            q.push(make_pair(name, t-qt));
        }
        q.pop();
    }
    return 0;
}

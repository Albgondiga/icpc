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
#define mkp make_pair
int n, m;

int valid(int i, int j) {
    return ((i>=0)&&(j>=0)&&(i<n)&&(j<m));
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    char c;
    cin>>n>>m;
    vector<vector<bool> > blocked(n, vector<bool> (m));
    vector<vector<bool> > visited(n, vector<bool> (m));
    vector<vector<char> > matOg(n, vector<char> (m));
    forn(i, n) {
        forn(j, m) {
            cin>>c;
            matOg[i][j] =c;
        }
    }

    forn(i, n) {
        forn (j, m) {
            c=matOg[i][j];
            if (c=='.') continue;
            blocked[i][j]=true;
            if (c=='>') for (int k=1; (j+k<m)&&matOg[i][j+k]=='.'; k++) blocked[i][k+j]=true;
            if (c=='<') for (int k=1; (j-k>=0)&&matOg[i][j-k]=='.'; k++) blocked[i][j-k]=true;
            if (c=='v') for (int k=1; (i+k<n)&&matOg[i+k][j]=='.'; k++) blocked[i+k][j]=true;
            if (c=='^') for (int k=1; (i-k>=0)&&matOg[i-k][j]=='.'; k++) blocked[i-k][j]=true;
        }
    }
    if (debug) {
        cout<<"BLOQUEOS:"<<endl;
        forn(i, n) {
            forn(j, m) {
                cout<<blocked[i][j];
            }
            cout<<endl;
        }
    }
    vector<vector<ii > > papa(n, vector<ii > (m));
    queue<ii> q;
    papa[0][0]=make_pair(0, 0);
    visited[0][0]=true;
    bool mamo=false;
    if (blocked[0][0]) mamo=1;
    q.push(papa[0][0]);
    bool won=false;
    int deltaI[4]={-1, 1, 0, 0}, deltaJ[4]={0, 0, -1, 1};

    while(!q.empty()&&!mamo) {
        ii s=q.front(); q.pop();
        if (s.first==n-1&&s.second==m-1) {
            won=1;
            break;
        }
        forn(i, 4) {
            ii u;
            u.first=s.first+deltaI[i];
            u.second=s.second+deltaJ[i];

            if (!valid(u.first, u.second)||blocked[u.first][u.second]) continue;

            if (visited[u.first][u.second]) continue;
            visited[u.first][u.second] =true;
            papa[u.first][u.second]=s;
            q.push(u);
        }
        
    }

    if (!won||mamo) cout<<-1<<endl;
    else {
        ii current; current.first=n-1; current.second=m-1;
        while(current.first!=0||current.second!=0) {
            matOg[current.first][current.second]='X';
            current=papa[current.first][current.second];
        }

        matOg[0][0]='X';

        forn(i, n) {
            forn(j, m) {
                cout<<matOg[i][j];
            }
            cout<<endl;

        }
    }

}

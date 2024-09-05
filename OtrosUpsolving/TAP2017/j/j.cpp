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
    int indx=1;
    vector<set<int>> queries;
    map<string, int> id;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    queries.resize(n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            string s; cin>>s;
            if (!id[s]) id[s]=indx++;
            queries[i].insert(id[s]);
        }
    }
    vector<vector<int>> status(indx, vector<int>(indx, 1));
    forn(i,n) {
        forr(j, 1, indx) {
            // si esta en el query
            if (queries[i].find(j)!=queries[i].end()) {
                // ponerle cero a toda la gente del query
                for (auto u:queries[i]) {
                    status[j][u]=0;
                    status[u][j]=0;
                }
                continue;
            }

            // si no esta en el query
            forr(k, 1, indx) {
                if (queries[i].find(k) == queries[i].end()) {
                    status[j][k]=0;
                    status[k][j]=0;
                }
            }
        }
    }


    vector<bool> marked(indx);
    int nJ=0;

    forr(i,1, indx) {

        // si ya está asociado a alguien, siga
        if (marked[i]) continue;

        //marque como que ya lo asocié con alguien
        marked[i]=true;
        // revise toda la gente
        forr(j, 1, indx) {
            if (marked[j]||!status[i][j]) continue;
            // agarre al primero con el que sea pana y no esté agarrado
            marked[j]=true;
            break;
        }
        nJ++;
    }

    if (nJ==m) cout<<"S\n";
    else cout<<"N\n";
    
}

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
#define BS 8

void placeQueen(int r, ll& result, vector<bool>& col, vector<bool>& primaryD,
        vector<bool>& inverseD, vector<vector<char>>& board) {
    if (r == BS) result++;
    forn(c,BS) {
        if (!col[c] && !primaryD[r+c] && !inverseD[r-c+BS] && board[r][c] != '*') {
            // Poner reina
            col[c] = true;
            primaryD[r+c] = true;
            inverseD[r-c+BS] = true;
            ifd {
                forn(k,r) cout<<"   ";
                cout<<"Placed queen at "<<r<<" "<<c<<endl; 
            }
            placeQueen(r+1,result,col,primaryD,inverseD,board);
            // Quitar reina
            col[c] = false;
            primaryD[r+c] = false;
            inverseD[r-c+BS] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s;
    vector<vector<char>> board(BS);
    forn(i,BS) {
        cin>>s;
        forn(j,BS) board[i].pb(s[j]);
    }

    vector<bool> col(BS,false);
    vector<bool> primaryD(2*BS-1,false); // fila+columna=index
    vector<bool> inverseD(2*BS-1,false); //fila-columna+BS=index
    ll result = 0;
    placeQueen(0,result,col,primaryD,inverseD,board);
    cout<<result<<endl;
    return 0;
}

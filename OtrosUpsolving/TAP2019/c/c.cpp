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

const int MAX = 2000;
char grid[MAX][MAX];
bool centro[MAX][MAX];

int dI[4] = {0,0,-1,1};
int dJ[4] = {-1,1,0,0};
#define IZQ 0
#define DER 1
#define ARR 2
#define ABA 3

int h, w;

bool valid(int i, int j) {
    return (i >= 0 && i < h && j >= 0 && j < w);
}

int contarArriba(int i, int j) {
    int count = 0;
    while(valid(i+dI[ARR],j+dJ[ARR]) && grid[i+dI[ARR]][j+dJ[ARR]] == '*' 
            && !centro[i+dI[ARR]][j+dJ[ARR]]) {
        i += dI[ARR];
        j += dJ[ARR];
        if (valid(i+dI[IZQ],j+dJ[IZQ]) && valid(i+dI[DER],j+dJ[DER])
                && grid[i+dI[IZQ]][j+dJ[IZQ]]=='.' && grid[i+dI[DER]][j+dJ[DER]]=='.') {
            count++;
        } else {
            return -1;
        }
    }
    return count;
}
int contarAbajo(int i, int j) {
    if (debug) cout<<"REVISO HACIA ABAJO!!!"<<endl;
    int count = 0;
    while(valid(i+dI[ABA],j+dJ[ABA]) && grid[i+dI[ABA]][j+dJ[ABA]] == '*' 
            && !centro[i+dI[ABA]][j+dJ[ABA]]) {
        i += dI[ABA];
        j += dJ[ABA];
        if (debug) {
            cout<<"me fijo en ("<<i+dI[IZQ]<<", "<<j+dJ[IZQ]<<") y ("<<i+dI[DER]<<", "<<j+dJ[DER]<<") "<<endl;
        }
        if (valid(i+dI[IZQ],j+dJ[IZQ]) && valid(i+dI[DER],j+dJ[DER])
                && grid[i+dI[IZQ]][j+dJ[IZQ]]=='.' && grid[i+dI[DER]][j+dJ[DER]]=='.') {
            count++;
        } else {
            return -1;
        }
    }
    return count;
}
int contarDerecha(int i, int j) {
    int count = 0;
    while(valid(i+dI[DER],j+dJ[DER]) && grid[i+dI[DER]][j+dJ[DER]] == '*' 
            && !centro[i+dI[DER]][j+dJ[DER]]) {
        i += dI[DER];
        j += dJ[DER];
        if (valid(i+dI[ARR],j+dJ[ARR]) && valid(i+dI[ABA],j+dJ[ABA])
                && grid[i+dI[ARR]][j+dJ[ARR]]=='.' && grid[i+dI[ABA]][j+dJ[ABA]]=='.') {
            count++;
        } else {
            return -1;
        }
    }
    return count;
}
int contarIzquierda(int i, int j) {
    int count = 0;
    while(valid(i+dI[IZQ],j+dJ[IZQ]) && grid[i+dI[IZQ]][j+dJ[IZQ]] == '*' 
            && !centro[i+dI[IZQ]][j+dJ[IZQ]]) {
        i += dI[IZQ];
        j += dJ[IZQ];
        if (valid(i+dI[ARR],j+dJ[ARR]) && valid(i+dI[ABA],j+dJ[ABA])
                && grid[i+dI[ARR]][j+dJ[ARR]]=='.' && grid[i+dI[ABA]][j+dJ[ABA]]=='.') {
            count++;
        } else {
            return -1;
        }
    }
    return count;
}

int buscarCruz(int i, int j) {
    if (debug) cout<<"estoy buscando una cruz desde "<<i<<", "<<j<<endl;
    int x = contarIzquierda(i,j);
    //if(debug)cout<<"izq="<<x<<endl;
    int v1=contarDerecha(i, j);
    if (x > 0 &&v1>0&& x == v1) {
        int v2=contarArriba(i, j);
        if (v2>0&&x == v2) {
            int v3=contarAbajo(i, j);
            if(debug) cout<<"2x="<<x<<endl;
            if (v3>0&&x < v3) {
                if(debug) cout<<i<<" "<<j<<endl;
                centro[i][j] = 1;
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>h>>w;
    if(debug) cout<<h<<" "<<w<<endl;
    forn(i,h) {
        forn(j,w) {
            
            cin>>grid[i][j];
            if(debug) cout<<grid[i][j];
        }
        if (debug) cout<<endl;
    }


    ll count = 0;
    forn(i,h) {
        forn (j,w) {
            if (grid[i][j] == '*')
                count += buscarCruz(i,j);
        }
    }
    if(debug) {
    forn(i,h) {
        forn (j,w) {
            cout<<centro[i][j];
        }
        cout<<endl;
    }
    }
    cout<<count<<"\n";

    return 0;
}

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

const int INF = 1e9;
#define debug 0
#define ifd if (debug)

struct Trie {
    bool esta;
    map<char, Trie> hijos;
    Trie() { esta = false; }
    ll distancia = 0;
    ll completar = INF;

    ll insertar(const string& s, int pos, ll dist) {
        if (pos < int(s.size())) {
            distancia = dist;
            ll distPalabra = hijos[s[pos]].insertar(s, pos+1, dist+1);
            completar = min(completar, distPalabra-distancia);
            return distPalabra;
        } else {
            distancia = dist;
            esta = true;
            return dist;
        }
    }

    void insertar(const string& s) {
        insertar(s,0,0);
    }

    Trie* buscar(const string& s, int pos) {
        if (pos < int(s.size())) {
            if (hijos.find(s[pos]) != hijos.end()) {
                return hijos[s[pos]].buscar(s, pos+1);
            } else {
                return NULL;
            }
        } else {
            return this;
        }
    }

    Trie* buscar(const string& s) {
        return buscar(s,0);
    }

};

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Trie mainTrie;
    int n, q; cin>>n>>q;
    forn(i,n) {
        string s; cin>>s;
        mainTrie.insertar(s);
    }

    while (q--) {
        string s; cin>>s;
        Trie* wordTrie = mainTrie.buscar(s);

        if (wordTrie == NULL) cout<<-1<<"\n";
        else if (wordTrie->esta) cout<<0<<"\n";
        else cout<<wordTrie->completar<<"\n";
    } 

    return 0;
}

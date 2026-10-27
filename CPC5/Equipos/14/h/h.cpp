#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;

#define debug 1
#define ifd if (debug)

// https://codeforces.com/group/6V7amHIf8K/contest/723362/problem/H

// OJO: es uno-indexado, pero los queries los responde de manera 0-indexada
struct Hash {
    // usted va a tener:
    // el P primo por el que va a multiplicar las varas
    int P=1777771;
    // el MOD1 y MOD2 por el que va a modular todo
    int MOD[2];
    // el inverso modular de P en MOD 1, y en MOD 2
	int PI[2];
    // el prefixHash del string en MOD1 y el otro en MOD 2 (UNO INDEXADO)
	vector<int> h[2];
    // esto va a ser PI ^ i mod MOD1 y MOD2
    vector<int> pi[2];
	Hash(string& s){
        // usamos el mod1, y el mod2
		MOD[0]=999727999;MOD[1]=1070777777;
        // el inv mult de p en mod1, y el inv mult de p en mod2
		PI[0]=325255434;PI[1]=10018302;
        // métales el tamaño correcto a c/u
		forr(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		forr(k,0,2){
            // el hash al inicio es cero
			h[k][0]=0;
            // inv Mult ^ 0 = 1
            pi[k][0]=1;
            // p es la potencia que lleva ahorita
			ll p=1;
            // legalmente, arme el prefix hash
			forr(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
    // saca el hash de [s, ..., e)
	ll get(int s, int e){
        // PARA MOD1:
        // h0 es el hash hasta e-1, quitándole el hash hasta s-1
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
        // vuélese los ceros del fondo
		h0=(1LL*h0*pi[0][s])%MOD[0];

        // PARA MOD2:
        // h1 es el hash hasta e-1, quitándole el hash hasta s-1
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
        // vuélese los ceros del fondo
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return (h0<<32)|h1;
	}
};

ll mpow(ll b, ll e, ll mod) {
	if (!e) return 1;
	ll a = mpow(b, e >> 1LL, mod);
	a *= a; a %= mod;
	if (e & 1) a *= b;
	return a % mod;
}

// letra[d] me da la letra equivalente al digito d
vector<char> letra = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

int n; ll m, p;
// String convertido
string s;
// String en numeros (input)
vector<ll> vs;
// Matriz de hashes del problema
vector<vector<ll>> M;
// largo[i] me dice cuantos digitos tiene s[i]
vector<ll> largo;
// eq[i] me dice que s[i] empieza en eq[i].first y termina en eq[i].second en s
vector<ii> eq;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

	cin >> n >> p >> m;
	vs.resize(n);
	forn(i, n) cin >> vs[i];

    // Calculo la matriz
    M.resize(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        ll hash = 0;
        for (int j = i; j < n; j++) {
            ll termino = vs[j];
            termino *= mpow(p, j-i, m);
            termino %= m;

            hash += termino;
            hash %= m;
            M[i][j] = hash;
        }
    }

    s = "";
    // Creo el string nuevo
    largo.assign(n,0);
    forn(i,n) {
        ll val = vs[i];
        s.push_back('A');
        while (val > 0) {
            largo[i]++;
            ll d = (val % 10);
            val /= 10LL;
            s.push_back(letra[d]);
        }
        s.push_back('A');
    }

    // Calculo los indices nuevos
    int count = 0;
    eq.resize(n);
    forn(i,n) {
        eq[i].first = count;
        eq[i].second = eq[i].first + largo[i] + 1;
        count += (largo[i] + 2);
    }

    Hash h(s);
    vector<ll> h1, h2;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            h1.push_back(M[i][j]);
            h2.push_back(h.get(eq[i].first, eq[j].second+1));
        }
    }

    sort(h1.begin(), h1.end());
    sort(h2.begin(), h2.end());
    
    ll ans = 0;

    ll x = 1;
    for (int i = 1; i < h1.size(); i++) {
        if (h1[i] != h1[i-1]) {
            ans += (x*(x-1))/2;
            x = 1;
        } else {
            x++;
        }
    }
    ans += (x*(x-1))/2;

    x = 1;
    for (int i = 1; i < h2.size(); i++) {
        if (h2[i] != h2[i-1]) {
            ans -= (x*(x-1))/2;
            x = 1;
        } else {
            x++;
        }
    }
    ans -= (x*(x-1))/2;

    cout<<ans*2<<"\n";

    return 0;
}
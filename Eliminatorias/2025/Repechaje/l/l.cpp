#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

ll hashsote(string& s) {
    ll ans = 0, mod = 999727999;
    ll exp = 1;
    forn(i, s.size()) {
        ans = (ans+(s[i]-'a')*exp) % mod;
        exp = (exp*31) % mod;
    }
    return ans;
}

int n, m, q, k;
// Valores {x,y} de cada palabra del diccionario
map<ll, pair<ll,ll>> valores;
// Candidatos de cada hash
map<ll, vector<ll>> candidatos;
set<ll> estaDicc, tieneCand;
// Base tiene las palabras de la base de conocimiento, dicc las del diccionario
vector<string> base, dicc;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n) {
        string p; cin>>p;
        ll x, y; cin>>x>>y;
        ll h = hashsote(p);

        dicc.push_back(p);
        estaDicc.insert(h);
        valores[h] = {x,y};
    }

    cin>>m;
    forn(i,m) {
        string s; cin>>s;
        base.push_back(s);
    }

    cin>>q>>k;
    // Preprocesar candidatos
    forn(i,m-1) {
        string& curr = base[i];
        vector<string> window(k+1);
        window[1] = curr;
        
        // Preproceso los windows que terminan en base[i]
        for (int j = k; j > 1; j--) {
            if (i < j-1) continue;
            window[j] = base[i-j+1]+" "+window[j-1];
        }
        // Le calculo el hash a cada window y le agrego el candidato al mapa
        forr(j, 1, k+1) {
            ll h1 = hashsote(window[j]), h2 = hashsote(base[i+1]);
            candidatos[h1].push_back(h2);
            tieneCand.insert(h1);
        }
    }

    while (q--) {
        // Leo las palabras
        int f; cin>>f;
        vector<string> words(f);
        for (string& s : words) cin>>s;

        // ans va a tener la mas similar
        string ans = "*";
        bool respondido = false;

        // Voy por tamano de window de grande a pequeno
        for (int i = k; (i >= 1) and (not respondido) and (f-i >= 0); i--) {
            // Calculo el window de tamano k de mis palabras
            string s = words[f-i];
            for (int j = f-i+1; j < f; j++) {
                s += " "+words[j];
            }
            ll hWindow = hashsote(s);

            // Si no tiene candidatos siga
            if (tieneCand.find(hWindow) == tieneCand.end()) continue;

            // Si tiene candidatos aqui termina todo, no tengo que revisar window mas pequenas
            respondido = true;
            ll maxi = -1e18, optima = -1;
            // Voy por cada palabra del diccionario
            for (string& palabra : dicc) {
                ll hDicc = hashsote(palabra);
                ll dist = 0;

                // Paso por todos los candidatos y calculo la similitud (dist)
                vector<ll>& v = candidatos[hWindow];
                for (ll& candidato : v) {
                    pair<ll,ll> valCand = {0,0}, valDicc = valores[hDicc];

                    if (estaDicc.find(candidato) != estaDicc.end()) 
                        valCand = valores[candidato];

                    dist += ((valCand.first * valDicc.first) + (valCand.second * valDicc.second));
                }

                // Actualizo la respuesta si es mayor
                if (dist > maxi) {
                    maxi = dist;
                    optima = hDicc;
                }
            }

            // Comparo hashes para "deshashear" la respuesta
            for (string& palabra : dicc) {
                ll comp = hashsote(palabra);
                if (comp == optima) {
                    ans = palabra;
                    break; 
                }
            }
        }

        for (string& w : words) cout<<w<<" ";
        cout<<ans<<"\n";
    }


    return 0;
}

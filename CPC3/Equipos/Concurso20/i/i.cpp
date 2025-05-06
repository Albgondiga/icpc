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
typedef pair<ll, ll> ii;
#define iii pair<ii, ll>

#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;
#define plazo first.first
#define skip first.second
#define precio second
#define debug 0
#define ifd if (debug&&i<=26)
const ll END=1e6;



int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    
    vector<ll> costo(1e6+3);
    vector<ll> sCosto(1e6+3);
    // me dice si en un dia hay gente
    vector<ll> gente(1e6+3);
    // me dice cuánta gente hay hasta el día i
    vector<ll> sGente(1e6+3);
    cin>>n>>k;

    ll minPrecio=1e9+7;
    forn(i, n) {
        int x; cin>>x;
        cin>>costo[x];
        gente[x]++;
    }

    vector<ll> ultimo(1e6+3);
    ultimo[0]=(gente[0])?0:-1;
    // el pSum de precios y gente
    sCosto[0]=costo[0];
    sGente[0]=gente[0];
    forr(i, 1, 1e6+3) {
        sCosto[i]+=costo[i]+sCosto[i-1];
        ultimo[i]=(gente[i])?i:ultimo[i-1];
        sGente[i]+=gente[i]+sGente[i-1];
    }


    vector<ll> primeraAparicion(1e4+3, -1);
    forn(i, 1e6) if (primeraAparicion[sGente[i]]==-1) primeraAparicion[sGente[i]] = i;
    

    vector<iii> tickets(k);
    forn(i, k) {
        cin>>tickets[i].plazo>>tickets[i].skip>>tickets[i].precio;
        if(tickets[i].skip) minPrecio=min(minPrecio, tickets[i].precio);
    }
    

    vector<ll> solve(1e6+3);
    for(int i=1e6; i>=0; i--) {
        // si esta al final legalmente es o comprarlo a usted o al mae más chiquito
        if (i==1e6) {
            solve[i]=min(costo[i], minPrecio);
            continue;
        }

        solve[i]=costo[i]+solve[i+1];
        
        // ahora revise todos los tickets
        for(iii kT:tickets) {
            ll cPlazo=kT.plazo, cSkips=kT.skip, cPrecio=kT.precio;
            ll x2 = cPrecio;

            // target va a ser la cantidad de gente que va a haber brincado given los skips del ticket
            ll target=0;
            // primero averigua cuánta gente tiene que haber brincado antes de empezar ese día
            if (i>0) target=sGente[i-1];
            // ahora sume la cantidad de gente que se va a brincar
            target+=cSkips;
            int endPlazo=min(i+cPlazo-1, END);
            // si la cantidad de gente que va a haber brincado es mayor que la cantidad de gente que hay en total, ya de fijo sabe su respuesta para ese ticket
            if (target>=n) {
                if (primeraAparicion[n]<=endPlazo) {
                    solve[i] = min(solve[i], x2);
                    continue;
                }
                int nxt=(ultimo[endPlazo]>=0)?ultimo[endPlazo]:endPlazo;
                solve[i]=min(solve[i], x2+solve[nxt+1]);
            }

            // si no, busque la primera aparición de esa cantidad de gente
            int finalPos=primeraAparicion[target];
            int sigPos;
            // si por algun motivo extragno no se puede brincar todo eso, queda en i+cPlazo 
            if (finalPos>i+cPlazo-1) sigPos=(ultimo[endPlazo]>=0)?ultimo[endPlazo]+1:endPlazo;
            
            // si si se podia brincar todo eso, brinqueselo y ya
            else sigPos=finalPos+1;
            x2 +=solve[sigPos];
            solve[i] = min(solve[i], x2);
        }

    }


    cout<<solve[0]<<endl;

}
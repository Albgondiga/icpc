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
#define iii pair<pair<int, int>, int> 
#define primero first.first
#define segundo first.second
#define tercero second

#define debug 0

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    set<iii> redondos, cuadrados, total;
    map<int, ii> m;
    map<int, bool> esRedondo;
    int maxD=0;
    for (int i=1; i<=n; i++) {
        char c; cin>>c;
        if (c=='D') esRedondo[i]=true;
        else esRedondo[i]=false;
        int inicio, fin; cin>>inicio>>fin;
        if (debug) cout<<"leí "<<inicio<<", "<<fin<<endl;
        ii p=make_pair(inicio, fin);
        m[i]=p;

        iii open; 
        
        open.primero =inicio;
        open.segundo=0;
        open.tercero =i;
        total.insert(open);

        iii close;
        close.primero=fin;
        close.segundo=1;
        close.tercero =i;
        total.insert(close);

    }


    for (iii u:total) {
        if (debug) cout<<"saqué ("<<u.primero<<", "<<u.segundo<<", "<<u.tercero<<")"<<endl;
        if (u.segundo==0) {
            if (debug) cout<<"es un open"<<endl;
            // si es redondo
            if (esRedondo[u.tercero]) {
                if (debug) cout<<"es redondo"<<endl;
                redondos.insert(u);
            }
            // si es cuadrado
            else {
                cuadrados.insert(u);
                if (debug) cout<<"es cuadrado"<<endl;
            }
            continue;
        }
        if (debug) cout<<"es un close"<<endl;
        //ok, usted es cierre
        // si es redondo
        if (esRedondo[u.tercero]) {
            if (debug) cout<<"es redondo";
            int openSuyo = m[u.tercero].first;
            if (debug) cout<<"mi open es "<<openSuyo<<endl;
            if (cuadrados.begin()!=cuadrados.end()) {
                if (debug) cout<<"caigo dentro de un paréntesis cuadrado"<<endl;
                int izqOtro=(*cuadrados.begin()).first.first;

                if (debug) cout<<"el cuadrado más a la izq abre en "<<izqOtro<<endl;
                
                if (izqOtro<openSuyo) {
                    if (debug) cout<<"cae fuera de mi redondo"<<endl;
                    maxD=max(maxD, (u.primero-openSuyo));
                }

                else if (izqOtro!=u.primero) {
                    if (debug) cout<<"cae dentro de mi redondo"<<endl;
                    maxD=max(maxD, (u.primero-izqOtro));
                }
            }

            iii p; p.primero=openSuyo; p.segundo=0; p.tercero=u.tercero;
            redondos.erase(p);
        }


        // si es cuadrado

        else {
            if (debug) cout<<"es cuadrado"<<endl;
            int openSuyo = m[u.tercero].first;

            if (debug) cout<<"mi open es "<<openSuyo<<endl;

            if (redondos.begin()!=redondos.end()) {
                if (debug) cout<<"caigo dentro de un paréntesis redondo"<<endl;

                int izqOtro=(*redondos.begin()).first.first;

                if (debug) cout<<"el redondo más a la izq abre en "<<izqOtro<<endl;

                if (izqOtro<openSuyo) {
                    if (debug) cout<<"cae fuera de mi cuadrado"<<endl;
                    maxD=max(maxD, (u.primero-openSuyo));
                }

                else if (izqOtro!=u.primero) {
                    if (debug) cout<<"cae dentro de mi cuadrado"<<endl;
                    maxD=max(maxD, (u.primero-izqOtro));
                }
            }

            iii p; p.primero=openSuyo; p.segundo=0; p.tercero=u.tercero;
            cuadrados.erase(p);
        }
    }


    cout<<maxD<<endl;




}

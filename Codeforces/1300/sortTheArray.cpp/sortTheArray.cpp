#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

int n;
vector<ll> a;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    a.resize(n);
    forn(i,n) cin>>a[i];

    if (n == 1) {
        cout<<"yes\n"<<1<<" "<<1<<"\n";
        return 0;
    }
    if (n == 2) {
        if (a[0] > a[1]) {
            cout<<"yes\n"<<1<<" "<<2<<"\n"; 
        } else {
            cout<<"yes\n"<<1<<" "<<1<<"\n";
        }
        return 0;
    }

    /*
    Tres casos:
    1 ___...... 
    2 ......___ 
    3 ...___... 
    */
    bool possible = true;
    int l = -1, r = -1;
    // 1 ___...... 
    if (a[0] > a[1]) {
        l = 0, r = n-1;
        // Busco secuencia decreciente desde el incio
        for (int i = 2; i < n; i++) {
            if (a[i-1] < a[i]) {
                r = i-1;
                break;
            }
        }
        // Si todo es decreciente no hay problema
        if (r < n-1) {
            // Si no, reviso el pegue
            if (a[l] > a[r+1]) {
                possible = false;
            } else {
                // Y verifico que todo sea creciente hasta el final
                for (int i = r+1; i < n; i++) {
                    if (a[i-1] > a[i]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
    } else {
        // Busco hasta donde llega la primera secuencia creceinte
        for (int i = 2; i < n; i++) {
            if (a[i-1] > a[i]) {
                l = i-1; r = n-1;
                break;
            }
        }
        // Si todo es creciente no hay problema
        if (l != -1) {
            // Si en algun momento cambia la monotonia, busco hasta 
            // donde llega la secuencia decreciente
            for (int i = l+1; i < n; i++) {
                if (a[i-1] < a[i]) {
                    r = i-1;
                    break;
                }
            }
            // 2 ......___
            if (r == n-1) {
                // Si llega hasta el final reviso el pegue
                ifd cout<<"Caso 2"<<endl;
                ifd cout<<"l = "<<l<<", r ="<<r<<endl;
                if (a[r] < a[l-1]) {
                    possible = false;
                }
            } else { // 3 ...___... 
                // Si no llega hasta el final, verifico que lo que 
                // sigue sea creciente hasta el final
                ifd cout<<"Caso 3"<<endl;
                ifd cout<<"l = "<<l<<", r ="<<r<<endl;
                for (int i = r+1; i < n; i++) {
                    if (a[i-1] > a[i]) {
                        possible = false;
                        break;
                    }
                }
                // Y reviso los pegues
                if (a[l] > a[r+1] || a[r] < a[l-1]) {
                    possible = false;
                }
            }
        }
    }

    if (possible) {
        if (l == -1 && r == -1) {
            cout<<"yes\n"<<1<<" "<<1<<"\n";
        } else {
            cout<<"yes\n"<<l+1<<" "<<r+1<<"\n";
        }
    }
    else cout<<"no\n";

    return 0;
}
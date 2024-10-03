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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    int n;
    while (t--) {
        cin>>n;
        string password = "", q = "";
        bool ans0, ans1;
        forn(i,n) {
            ifd cout<<" i = "<<i<<endl;
            q = password;
            q += '0';
            cout<<"? "<<q<<"\n";
            cout.flush();
            cin>>ans0;

            ifd cout<<"Voy a cambiar la pos "<<i<<" de q por un 1"<<endl;
            q[i] = '1';
            cout<<"? "<<q<<"\n";
            cout.flush();
            cin>>ans1;

            if (ans1) {
                password += '1';
            } else {
                if (ans0) {
                    password += '0';
                } else {
                    password.erase(0,1);
                    q = password;
                    q += '0';
                    cout<<"? "<<q<<"\n";
                    cout.flush();
                    cin>>ans0;

                    q[i] = '1';
                    cout<<"? "<<q<<"\n";
                    cout.flush();
                    cin>>ans1;

                    if (ans1) {
                        password += '1';
                    } else {
                        password += '0';
                    }
                }
            }
        }
        cout<<"! "<<password<<"\n";
        cout.flush();

        ifd cout<<endl;
    }

    return 0;
}

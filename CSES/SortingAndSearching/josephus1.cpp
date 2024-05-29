#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n; 
    cin>>n;
    set<ll> a; // COnjunto si alguien esta o no, no hay repeticiones
    for(int i = 1; i<=n; i++) a.insert(i);
    auto it = a.find(2); // Si 2 esta, me devuelve el iterador y sino me devuelve el end
    if(it == a.end()){
        cout<<"1\n";
    }
    else{
        while(a.size()){
            ll cur = *it;
            cout<<cur<<" ";
            a.erase(it); // Pasar el iterador o el numero it/cur
            if(a.size() == 0) break;
            it = a.upper_bound(cur); // Primer numero mas grande que cur
                                    // it.lower_bound(cur) primer numero mayor o igual a cur
            if(it == a.end()) it = a.begin();
            it++;
            if(it == a.end()) it = a.begin();
        }
        cout<<"\n";
    }
}

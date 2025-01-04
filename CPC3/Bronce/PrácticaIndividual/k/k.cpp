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

bool compareRate(pair<long double,int>& p1, pair<long double,int>& p2) { 
    if (p1.first != p2.first) {
        return p1.first > p2.first;
    } else {
        return p1.second < p2.second;
    }
} 

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll N; cin>>N;
    vector<pair<long double,int>> rate(N);
    forn(i,N) {
        long double A, B; cin>>A>>B;
        long double r = A/(A+B);
        ifd cout<<"r = "<<r<<endl;
        rate[i] = make_pair(r,i+1);
    }
    sort(rate.begin(), rate.end(), compareRate);
    forn(i,N) {
        ifd cout<<rate[i].first<<" "<<rate[i].second<<"\n";
        cout<<rate[i].second<<" ";
    }
    cout<<"\n";
    return 0;
}
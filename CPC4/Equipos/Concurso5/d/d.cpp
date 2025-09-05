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

#define debug 1
#define ifd if (debug)

#define primera 0
#define segunda 1

double p, r, y;

// solve1 me da w/s si tengo e/n o viceversa
// suma = v1-v2
double solve1(double suma, int var, double val) {
    if (var == primera) {  // Tengo primera variable
        return val-suma;  // v2 = v1 - suma
    }
    // v1 = suma + v2
    return suma+val;
}

// solve2 me da e/w o n/s a partir de las otras dos que ya tengo
// suma1 = v1 - v2
// suma2 = v1 + v2
pair<double,double> solve2(double suma1, double suma2) {
    // v1 = suma1+v2 => suma2 = suma1+2*v2 
    double v2 = (suma2-suma1)/2.0;
    return {suma1+v2, v2};
}

bool valid(double x, double m) {
    return (abs(x) <= m+0.000001 and x >= -4.000001 and x <= 4.000001);
}

bool isSolution(double n, double e, double s, double w, double m) {
    return (valid(n,m) and valid(e,m) and valid(s,m) and valid(w,m));
}

pair<bool, vector<double>> check(double m) {
    // e
    {
        double e = m;
        double w = solve1(p, primera, e); 
        pair<double,double> x = solve2(r, y-(e+w));
        double n = x.first, s = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    {
        double e = -m;
        double w = solve1(p, primera, e);
        pair<double,double> x = solve2(r, y-(e+w));
        double n = x.first, s = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    // w
    {
        double w = m;
        double e = solve1(p, segunda, w);
        pair<double,double> x = solve2(r, y-(e+w));
        double n = x.first, s = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    {
        double w = -m;
        double e = solve1(p, segunda, w);
        pair<double,double> x = solve2(r, y-(e+w));
        double n = x.first, s = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    // n
    {
        double n = m;
        double s = solve1(r, primera, n);
        pair<double,double> x = solve2(p, y-(n+s));
        double e = x.first, w = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    {
        double n = -m;
        double s = solve1(r, primera, n);
        pair<double,double> x = solve2(p, y-(n+s));
        double e = x.first, w = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    // s
    {
        double s = m;
        double n = solve1(r, segunda, s);
        pair<double,double> x = solve2(p, y-(n+s));
        double e = x.first, w = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    {
        double s = -m;
        double n = solve1(r, segunda, s);
        pair<double,double> x = solve2(p, y-(n+s));
        double e = x.first, w = x.second;
        if (isSolution(n,e,s,w,m)) return {true, {n,e,s,w}};
    }
    return {false, {}};
}

vector<double> search() {
    double a = 0.000001, b = 4.000000;
    vector<double> ans;
    for(int i = 1; i <= 100; i++) {
        double m;
        if (b > 2.0*a) m = sqrt(a*b);
        else m = (a+b)/2.0;
        pair<bool, vector<double>> x = check(m);
        if (x.first) {
            b = m;
            ans = x.second;
        } else {
            a = m;
        }
    }
    return ans;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout<<setprecision(6)<<fixed;

    int q; cin>>q;
    while (q--) {
        string dummy;
        cin>>dummy; p = stod(dummy);
        cin>>dummy; r = stod(dummy);
        cin>>dummy; y = stod(dummy);

        vector<double> ans = search();
        for (auto x : ans) cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}

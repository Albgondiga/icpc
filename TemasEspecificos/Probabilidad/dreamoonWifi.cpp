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

#define debug 1
#define ifd if (debug)

// https://codeforces.com/problemset/problem/476/B

int fact(int x) {
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res *= i;
    }
    return res;
}

int exp(int x, int e) {
    int res = 1;
    for (int i = 0; i < e; i++) {
        res *= x;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string str1, str2; cin>>str1>>str2;
    int s1 = 0, s2 = 0, k = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == '+') s1++;
        else s1--;
        if (str2[i] == '+') s2++;
        else if (str2[i] == '-') s2--;
        else k++;
    }

    // a-b = s1-s2
    // a+b = k
    // a = (s1-s2+k)/2, b = (k-s1+s2)/2

    double ans = 0;
    int a = (s1-s2+k)/2, b = (k-s1+s2)/2;
    if (((s1-s2+k) % 2) or ((k-s1+s2) % 2) or (a > k) or (-b < -k)) {
        cout<<setprecision(9)<<fixed<<ans<<"\n";
        return 0;
    }

    ans = (double)fact(k)/(double)(fact(a)*fact(k-a));
    ans /= (double)exp(2,k);

    cout<<setprecision(9)<<fixed<<ans<<"\n";
    return 0;
}

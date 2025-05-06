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

#define debug 1
#define ifd if (debug)

int n, k;

bool primerosDos(vector<int>& v) {
    int ans = 0, menores = 0, m = 0;

    int i = 0, j = 0;
    while (i < n-2) {
        if (v[i] <= k) menores++;
        m++;
        if (menores == 0) {
            i++;
            continue;
        }
        if (m % 2 and menores > m/2) {
            ans++;
            break;
        } else if (m % 2 == 0 and menores >= m/2) {
            ans++;
            break;
        }
        i++;
    }
    if (ans == 0) return false;

    menores = 0, m = 0, j = i+1;
    while (j < n-1) {
        if (v[j] <= k) menores++;
        m++;
        if (menores == 0) {
            j++;
            continue;
        }
        if (m % 2 and menores > m/2) {
            ans++;
            break;
        } else if (m % 2 == 0 and menores >= m/2) {
            ans++;
            break;
        }
        j++;
    }

    if (ans < 2) return false;
    return true;
}

bool ultimosDos(vector<int>& v) {
    int ans = 0, menores = 0, m = 0;

    int i = n-1, j = n-1;
    while (i > 1) {
        if (v[i] <= k) menores++;
        m++;
        if (menores == 0) {
            i--;
            continue;
        }
        if (m % 2 and menores > m/2) {
            ans++;
            break;
        } else if (m % 2 == 0 and menores >= m/2) {
            ans++;
            break;
        }
        i--;
    }
    if (ans == 0) return false;

    menores = 0, m = 0, j = i-1;
    while (j > 0) {
        if (v[j] <= k) menores++;
        m++;
        if (menores == 0) {
            j--;
            continue;
        }
        if (m % 2 and menores > m/2) {
            ans++;
            break;
        } else if (m % 2 == 0 and menores >= m/2) {
            ans++;
            break;
        }
        j--;
    }

    if (ans < 2) return false;
    return true;
}

bool primeroYultimo(vector<int>& v) {
    int ans = 0, menores = 0, m = 0;

    int i = 0, j = n-1;
    while (i < n-2) {
        if (v[i] <= k) menores++;
        m++;
        if (menores == 0) {
            i++;
            continue;
        }
        if (m % 2 and menores > m/2) {
            ans++;
            break;
        } else if (m % 2 == 0 and menores >= m/2) {
            ans++;
            break;
        }
        i++;
    }
    if (ans == 0) return false;

    menores = 0, m = 0;
    while (j >= i+2) {
        if (v[j] <= k) menores++;
        m++;
        if (menores == 0) {
            j--;
            continue;
        }
        if (m % 2 and menores > m/2) {
            ans++;
            break;
        } else if (m % 2 == 0 and menores >= m/2) {
            ans++;
            break;
        }
        j--;
    }

    if (ans < 2) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        cin>>n>>k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];

        // Para ganar necesito al menos dos intervalos
        // con mediana <= k

        if (primerosDos(v) or primeroYultimo(v) or ultimosDos(v)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}

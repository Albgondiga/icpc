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
const ll INF=1e13+7;
#define debug 0
#define ifd if (debug)

int n, q;
vector<string> nums;
vector<int> v[6];

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    nums.resize(n);
    forn(i,n) cin>>nums[i];
    cin>>q;
    
    sort(nums.begin(), nums.end());

    forn(i,6) v[i].resize(n);
    forn(i,n) {
        v[0][i] = nums[i][0]-'0';
        v[1][i] = nums[i][1]-'0';
        v[2][i] = nums[i][2]-'0';
        v[3][i] = nums[i][3]-'0';
        v[4][i] = nums[i][4]-'0';
        v[5][i] = nums[i][5]-'0';
    }

    while (q--) {
        string reg; cin>>reg;
        ifd cout<<"NUEVO CASO"<<endl;
        // Buscar en intervalos [l, r)
        int l = 0, r = v[0].size();

        forn(i,6) {
            if (l == r) break;

            int digit = reg[i]-'0';
            int diff = 10 - digit;
            int counter = diff - 1;

            while (true) {
                auto i1 = lower_bound(v[i].begin()+l, v[i].begin()+r, counter);
                auto i2 = upper_bound(v[i].begin()+l, v[i].begin()+r, counter);

                if (i1 == v[i].begin()+r) {
                    counter--;
                } else {
                    if ((*i1) == counter) {
                        l = i1-v[i].begin();
                        r = i2-v[i].begin();
                        ifd cout<<counter<<" me sirve para "<<digit<<endl;
                        ifd cout<<"l = "<<l<<", r = "<<r<<endl;
                        break;
                    } 
                    counter--;
                }
                if (counter == -1) counter = 9;
                else if (counter == diff) {
                    i1 = lower_bound(v[i].begin()+l, v[i].begin()+r, counter);
                    i2 = upper_bound(v[i].begin()+l, v[i].begin()+r, counter);
                    l = i1-v[i].begin();
                    r = i2-v[i].begin();
                    break;
                }
            }
        }
        cout<<nums[l]<<"\n";
    }

    return 0;
}

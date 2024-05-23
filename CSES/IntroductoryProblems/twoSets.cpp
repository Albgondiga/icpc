#include <bits/stdc++.h>

using namespace std;

#define debug 0
#define ifd if(debug)

int main() {
    int n;
    cin >> n;
    int mod = n%4;
    int counter = 1;
    switch (mod) {
        case 0:
            cout << "YES" << "\n";
            cout<<n/2<<"\n";
            while (counter <= n/4) {
                cout<<counter<<" "<<n-counter+1<<" ";
                counter++;
            }
            cout<<"\n";
            cout<<n/2<<"\n";
            while (counter <= n/2) {
                cout<<counter<<" "<<n-counter+1<<" ";
                counter++;
            }
            cout<<"\n";
            return 0;
            break;
        case 1:
            cout << "NO" << "\n";
            break;
        case 2:
            cout << "NO" << "\n";
            break;
        case 3:
            // Le doy 1 y 2 al primero, 3 al segundo y proceso 
            // los que quedan (%4 == 0)
            cout << "YES" << "\n";
            cout<<(n-3)/2+2<<"\n";
            cout<<"1 2 ";
            while (counter <= (n-3)/4) {
                cout<<counter+3<<" "<<n-counter+1<<" ";
                counter++;
            }
            cout<<"\n";
            cout<<(n-3)/2+1<<"\n";
            cout<<"3 ";
            while (counter <= (n-3)/2) {
                cout<<counter+3<<" "<<n-counter+1<<" ";
                counter++;
            }
            cout<<"\n";
            return 0;
            break;
   }
   return 0;
}
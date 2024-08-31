#include <bits/stdc++.h>

using namespace std;

// CP Algorithms
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// CSES
vector<int> z(string s) {
    int n = s.size(); 
    vector<int> z(n); 
    int x = 0, y = 0; 
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1)); 
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) { 
            x = i; y = i+z[i]; 
            z[i]++; 
        } 
    } 
    return z; 
}
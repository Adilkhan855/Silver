#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

const int mod = 1e9 + 7, N = 2e6;

int fact[N];

int binpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, mod-2);
}

int cnk(int n, int k) {
    return fact[n] * inv(fact[k]) % mod * inv(fact[n-k]) % mod;
}

void solve() {
    int p, n; cin >> p >> n;
    
    if(p < 0) p = -p;
    
    int res = binpow(2, n-1);
    
    map<int, int> mp;
    
    for(int i = 2; i * i <= p; i++) {
        while(p % i == 0) {
            p /= i;
            mp[i]++;
        }
    }
    
    if(p > 1) mp[p]++;
    
    for(auto [key, val] : mp) {
        res = (res * cnk(n + val - 1, val)) % mod;
    }
    
    cout << res << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fact[0] = 1;
    
    for(int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    
    solve();
}

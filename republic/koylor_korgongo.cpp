#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

// #define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if(a < b) {
		return a = b, true;
	}
	return false;
}

const long long inf = 1e18;
const int N = 2e3;

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	bool flag = true;
	
	a.insert(a.begin(), 0);
	
	for(int i = 1; i <= n; i++) {
		if(a[i] != i) {
			flag = false;
			break;
		}
	}
	
	vector<ar<long long, 2>> dp(n + 1, {inf, inf});
	
	dp[0] = {0, 0};
	
	auto min_cost = [&](const int &i) -> long long {
		
		auto F = [&](const int &j) -> long long {
			return dp[j][1] + dp[i - j - 1][0];
		};
		
		if(flag) return F(i / 2);
		
		int l = 0, r = i-1;
        long long y = LLONG_MAX;
        while(l <= r) {
            int mid1 = l + (r-l)/3;
            int mid2 = r - (r-l)/3;
            long long f1 = F(mid1);
            long long f2 = F(mid2);
            y = min({y, f1, f2});
            if(f1 < f2) r = mid2 - 1;
            else l = mid1 + 1;
        }
        
        for(int j = max(0, l - N); j < min(i, l + N); j++) {
			chmin(y, F(j));
		}
		
		for(int j = max(0, r - N); j < min(i, r + N); j++) {
			chmin(y, F(j));
		}
        
        return y;
	};
	
	for(int i = 1; i <= n; i++) {
		chmin( dp[i][0], 2 * 1ll * i + dp[i / 2][0] + dp[i - (i / 2) - 1][0] );
		chmin( dp[i][1], 2 * 1ll * a[i] + min_cost(i) );
	}
	
	cout << dp[n][1] << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

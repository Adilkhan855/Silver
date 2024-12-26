/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void solve() {
	int n, m; cin >> n >> m;
	
	vector<string> spotty(n);
	for(auto &str : spotty) cin >> str;
	
	vector<string> plain(n);
	for(auto &str : plain) cin >> str;
	
	vector S(n, vector(m, 0));
	vector P(n, vector(m, 0));
	
	auto what = [&](char c) {
		if(c == 'A') return 1;
		if(c == 'C') return 2;
		if(c == 'G') return 3;
		return 4;
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			S[i][j] = what(spotty[i][j]);
			P[i][j] = what(plain[i][j]);
		}
	}
	
	vector<bool> A(10000);
	auto check = [&](int j1, int j2, int j3) {
		bool good = true;
		for(int i = 0; i < n; i++)
			A[S[i][j1] * 16 + S[i][j2] * 4 + S[i][j3]] = true;
		for(int i = 0; i < n; i++)
			if(A[P[i][j1] * 16 + P[i][j2] * 4 + P[i][j3]]) {
				good = false;
				break;
			}
		for(int i = 0; i < n; i++) {
			A[S[i][j1] * 16 + S[i][j2] * 4 + S[i][j3]] = false;
		}
		return good;
	};
	int ans = 0;
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			for(int k = j + 1; k < m; k++) {
				if(check(i, j, k)) {
					ans++;
				}
			}
		}
	}
	cout << ans << nl;
}

signed main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}

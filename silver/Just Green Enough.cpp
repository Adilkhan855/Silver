#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n; cin >> n;
	
	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<int>> ok(n, vector<int>(n));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			ok[i][j] = (a[i][j] >= 100);
		}
	}
	
	auto Answer = [&]() {
		int res = 0;
		for(int i = 0; i < n; i++) {
			vector<int> all_ones(n, true);
			for(int j = i; j < n; j++) {
				int run = 0;
				for(int k = 0; k < n; k++) {
					all_ones[k] &= ok[j][k];
					if(all_ones[k]) res += ++run;
					else run = 0;
				}
			}
		}
		return res;
	};
	
	int ans = Answer();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ok[i][j] = (a[i][j] > 100);
		}
	}
	
	ans -= Answer();
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

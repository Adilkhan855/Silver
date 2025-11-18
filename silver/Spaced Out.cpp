#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n; cin >> n;
	
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	auto Answer = [](const vector<vector<int>> &a) {
		int n = a.size() - 1;
		
		int ans = 0;
		
		for(int i = 1; i <= n; i++) {
			ar<int, 2> sum{};
			for(int j = 1; j <= n; j++) {
				sum[j & 1] += a[i][j];
			}
			ans += max(sum[0], sum[1]);
		}
		
		return ans;
	};
	
	auto Transpose = [](const vector<vector<int>> &a) {
		int n = a.size() - 1;
		
		vector<vector<int>> b(n + 1, vector<int>(n + 1));
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) b[j][i] = a[i][j];
		}
		
		return b;
	};
	
	cout << max(Answer(a), Answer(Transpose(a))) << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

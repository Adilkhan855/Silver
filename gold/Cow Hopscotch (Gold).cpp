#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

const int mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

void add_self(int &a, const int &b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

struct BIT {
	int n;
	
	vector<int> inds, bit;
	
	BIT() {}
	
	BIT(vector<int> inds) : n(inds.size()), inds(inds), bit(n + 1) {}
	
	int actual(int i) {
		return upper_bound(inds.begin(), inds.end(), i) - inds.begin();
	}
	
	void update(int i, int x) {
		i = actual(i);
		
		for(; i <= n; i += i & -i) add_self(bit[i], x);
	}
	
	int get(int i) {
		i = actual(i);
		
		int res = 0;
		
		for(; i >= 1; i -= i & -i) add_self(res, bit[i]);
		
		return res;
	}
};

const int N = 750 * 750;

BIT bits[N];

vector<int> inds[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	
	vector<vector<int>> a(n, vector<int>(m));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			int x = a[i][j];
			
			if(!inds[x].empty() && inds[x].back() == j) continue;
			
			inds[x].push_back(j);
		}
	}
	
	for(int i = 0; i < N; i++) {
		if(!inds[i].empty()) {
			bits[i] = BIT(inds[i]);
		}
	}
	
	vector<vector<int>> dp(n, vector<int>(m));
	
	vector<vector<int>> pref(n, vector<int>(m));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x = a[i][j];
			if(i == 0 && j == 0) {
				dp[i][j] = pref[i][j] = 1;
			} else if(i > 0 && j > 0) {
				dp[i][j] = add(pref[i - 1][j - 1], -bits[x].get(j - 1));
			}
			// cout << dp[i][j] << ' ';
		}
		// cout << nl;
		for(int j = 0; j < m; j++) {
			int x = a[i][j];
			bits[x].update(j, dp[i][j]);
			pref[i][j] = dp[i][j];
			if(i > 0) add_self(pref[i][j], pref[i - 1][j]);
			if(j > 0) add_self(pref[i][j], pref[i][j - 1]);
			if(i > 0 && j > 0) add_self(pref[i][j], -pref[i - 1][j - 1]);
		}
	}
	
	cout << dp[n - 1][m - 1] << nl;
}

signed main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

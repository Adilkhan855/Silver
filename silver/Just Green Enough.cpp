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

/** O(n ^ 2) solution
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
	
	auto sum = [](int n) {
		return n * (n + 1) / 2;
	};
	
	auto Answer = [&]() {
		int res = 0;
		vector<int> lst(n, n - 1);
		vector<int> to_add[1000];
		
		for(int i = n - 1; i >= 0; i--) {
			for(int j = i; j < n; j++) to_add[j].clear();
			
			for(int k = 0; k < n; k++) {
				if(ok[i][k] == 0) lst[k] = i - 1;
				else to_add[lst[k]].pb(k);
			}
			
			int cur = 0;
			
			vector<int> lf(n, -1), rg(n, -1);
			
			for(int j = n - 1; j >= i; j--) {
				for(auto k : to_add[j]) {
					int l = k, r = k;
					if(k && lf[k - 1] != -1) {
						l = lf[k - 1];
						cur -= sum(k - l);
					}
					if(k + 1 < n && rg[k + 1] != -1) {
						r = rg[k + 1];
						cur -= sum(r - k);
					}
					cur += sum(r - l + 1);
					lf[r] = l, rg[l] = r;
				}
				res += cur;
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
**/

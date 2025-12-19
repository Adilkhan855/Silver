#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) {
		cin >> x;
	}
	
	auto rec = [&](auto &&self, int l, int r, bool flag) -> string {
		int mn = 1e6 + 5;
		
		for(int i = l; i < r; i++) {
			mn = min(mn, a[i]);
		}
		
		for(int i = l; i < r; i++) {
			a[i] -= mn;
		}
		
		string ans;
		
		for(int i = 0; i < mn - 1; i++) {
			if(flag) {
				for(int j = l; j < r; j++) ans += 'R';
			} else {
				for(int j = l; j < r; j++) ans += 'L';
			}
			flag = !flag;
		}
		
		if(flag) {
			for(int i = l, j = i; i < r; i = j) {
				if(a[i] == 0) {
					ans += 'R';
					j++;
					continue;
				}
				
				while(j < n && a[j] > 0) {
					ans += 'R';
					j++;
				}
				
				ans += self(self, i, j, false);
			}
		} else {
			for(int i = r - 1, j = i; i >= l; i = j) {
				if(a[i] == 0) {
					ans += 'L';
					j--;
					continue;
				}
				
				while(j >= l && a[j] > 0) {
					ans += 'L';
					j--;
				}
				
				ans += self(self, j + 1, i + 1, true);
			}
		}
		
		return ans;
	};
	
	cout << rec(rec, 0, n, true) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

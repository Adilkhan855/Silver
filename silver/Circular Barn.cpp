#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 5e6 + 1, inf = 1e9 + 5;

int mvs[N];

bool used[N];
vector<int> pr;

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	int mn = inf;
	
	for(int i = 0; i < n; i++) {
		int val = (a[i] % 4 == 0 ? a[i] / 2 + 1 : mvs[a[i]]);
		mn = min(mn, val);
	}
	
	// cout << mn << '\n';
	
	for(int i = 0; i < n; i++) {
		int val = (a[i] % 4 == 0 ? a[i] / 2 + 1 : mvs[a[i]]);
		if(val == mn) {
			// cout << a[i] << '\n';
			cout << (a[i] % 4 ? "Farmer John" : "Farmer Nhoj") << '\n';
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	pr.reserve(N);
	
	used[0] = used[1] = true;
	
	pr.emplace_back(1);
	
	for(int i = 2; i < N; i++) {
		if(!used[i]) {
			pr.emplace_back(i);
			if(i * 1LL * i >= N) continue;
			for(int j = i * i; j < N; j += i) {
				used[j] = true;
			}
		}
	}
	
	memset(used, 0, sizeof(used));
	
	for(int i = (int)pr.size() - 1; i >= 0; i--) {
		for(int j = 0, x = pr[i]; x < N; j++, x += 4) {
			if(used[x]) break;
			used[x] = true;
			mvs[x] = j * 2 + 1;
		}
	}
	
	// for(int i = 1; i < N; i++) {
		// int mn = inf, mx = -inf;
		
		// for(const auto &x : pr) {
			// if(x > i) break;
			// if(!wins[i - x]) {
				// wins[i] = true;
				// mn = min(mn, mvs[i - x] + 1);
			// } else {
				// mx = max(mx, mvs[i - x] + 1);
			// }
		// }
		
		// if(wins[i]) mvs[i] = mn;
		// else mvs[i] = mx;
	// }
	
	// const int k = 1000;
	
	// for(int i = 1; i <= k; i++) {
		// if(wins[i]) {
			// cout << i << ": " << mvs[i] << '\n';
		// }
	// }
	
	// cout << '\n';
	
	// for(int i = 1; i <= k; i++) {
		// cout << wins[i] << ' ';
	// }
	
	// cout << '\n';
	
	// for(int i = 1; i <= k; i++) {
		// cout << mvs[i] << ' ';
	// }
	
	// cout << '\n';
	
	int tt; cin >> tt;
	while(tt--) solve();
}

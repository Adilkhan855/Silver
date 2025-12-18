#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, k; cin >> n >> k;
	
	vector<int> a(k), b(k);
	
	vector<int> used(n);
	
	for(auto &x : a) {
		cin >> x;
		x--;
		used[x] = true;
	}
	
	for(auto &x : b) {
		cin >> x;
		x--;
		used[x] = true;
	}
	
	auto f = [](vector<int> a, vector<int> b) {
		int n = a.size();
		
		vector<int> pos( (int)5e5, -1 );
		
		for(int i = 0; i < n; i++) {
			pos[a[i]] = i;
		}
		
		vector<int> cnt(n);
		
		for(int i = 0; i < n; i++) {
			if(pos[b[i]] == -1) continue;
			if(pos[b[i]] <= i) {
				cnt[i - pos[b[i]]]++;
			} else {
				cnt[n - (pos[b[i]] - i)]++;
			}
		}
		
		return *max_element(cnt.begin(), cnt.end());
	};
	
	int ans = f(a, b);
	
	reverse(a.begin(), a.end());
	
	ans = max(ans, f(a, b));
	
	cout << ans + (n - accumulate(used.begin(), used.end(), 0)) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
	setIO("cowdance");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, T; cin >> n >> T;
	
	vector<int> a(n);
	
	for(auto &u : a) cin >> u;
	
	auto check = [&](int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		int last = 0;
		for(int i = 0; i < n; i++) {
			if((int)pq.size() == k) {
				last = pq.top();
				pq.pop();
			}
			if(last + a[i] > T) return false;
			pq.emplace(last + a[i]);
		}
		return true;
	};
	
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << nl;
}

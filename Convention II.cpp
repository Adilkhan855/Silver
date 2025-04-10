#include <bits/stdc++.h>
using namespace std;

#define int long long
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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("convention2");
	int n; cin >> n;
	
	vector<int> a(n), t(n);
		
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> t[i];
	}
	
	vector<ar<int, 3>> cows;
	
	for(int i = 0; i < n; i++) {
		cows.pb({a[i], i, t[i]});
	}
	
	sort(all(cows));
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int ans = 0, time = cows[0][0] + cows[0][2];
	
	for(int i = 1; i < n || !pq.empty(); ) {
		while(i < n && cows[i][0] <= time) {
			pq.push(cows[i][1]);
			i++;
		}
		if(!pq.empty()) {
			int j = pq.top();
			pq.pop();
			ans = max(ans, time - a[j]);
			time += t[j];
		} else if(i < n) {
			time = cows[i][0] + cows[i][2];
			i++;
		}
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

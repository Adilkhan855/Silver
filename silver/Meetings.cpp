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
	setIO("meetings");
	int N, L; cin >> N >> L;
	
	vector<int> w(N), x(N), d(N);
	
	for(int i = 0; i < N; i++) {
		cin >> w[i] >> x[i] >> d[i];
	}
	
	vector<int> ind(N);
	
	iota(all(ind), 0);
	
	sort(all(ind), [&](int i1, int i2) {
		return x[i1] < x[i2];
	});
	
	vector<int> W, X, D;
	
	for(auto i : ind) {
		W.pb(w[i]);
		X.pb(x[i]);
		D.pb(d[i]);
	}
	
	swap(w, W), swap(x, X), swap(d, D);
	
	vector<int> lef, rig;
	
	for(int i = 0; i < N; i++) {
		if(d[i] == -1) lef.pb(x[i]);
		else rig.pb(x[i]);
	}
	
	vector<ar<int, 2>> v;
	
	for(int i = 0; i < (int)lef.size(); i++) {
		v.pb({lef[i], w[i]});
	}
	
	for(int i = 0; i < (int)rig.size(); i++) {
		v.pb({L - rig[i], w[lef.size() + i]});
	}
	
	sort(all(v));
	
	int end_time = -1;
	
	int tot_wt = 0, sum = accumulate(all(w), 0ll);
	
	for(auto [cur_time, wt] : v) {
		tot_wt += 2 * wt;
		if(tot_wt >= sum) {
			end_time = cur_time;
			break;
		}
	}
	
	queue<int> q;
	
	int ans = 0;
	
	for(int i = 0; i < N; i++) {
		if(d[i] == -1) {
			while(!q.empty() && x[q.front()] + 2 * end_time < x[i]) q.pop();
			ans += q.size();
		} else {
			q.emplace(i);
		}
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

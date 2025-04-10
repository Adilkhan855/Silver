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

/**
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

const int inf = 1e15;

struct SGT {
	int n; vector<int> t;
	
	SGT(vector<int> a) : n(a.size()), t(n << 1) {
		for(int i = 0; i < n; i++) t[i + n] = a[i];
		for(int i = n - 1; i > 0; i--) {
			t[i] = min(t[i << 1], t[i << 1 | 1]);
		}
	}
	
	void update(int i, int x) {
		for(t[i += n] = x; i > 0; i >>= 1) {
			t[i >> 1] = min(t[i], t[i ^ 1]);
		}
	}
	
	int get(int l, int r) {
		int res = inf;
		for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = min(res, t[l++]);
			if(r & 1) res = min(res, t[--r]);
		}
		return res;
	}
};

void solve() {
	setIO("convention2");
	int n; cin >> n;
	
	vector<int> a(n), t(n);
		
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> t[i];
	}
	
	SGT s(a);
	
	queue<ar<int, 2>> q;
	
	int mn = *min_element(all(a));
	
	for(int i = 0; i < n; i++) {
		if(a[i] == mn) {
			q.push({i, a[i]});
			break;
		}
	}
	
	set<pair<int, int>> st;
	
	for(int i = 0; i < n; i++) st.emplace(a[i], i);
	
	int ans = 0;
	
	while(!q.empty()) {
		auto [i, T] = q.front();
		q.pop();
		
		st.erase({a[i], i});
		
		T += t[i];
		a[i] = inf;
		s.update(i, inf);
		
		// cout << i + 1 << ' ' << T << nl;
		
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(s.get(0, mid) <= T) r = mid;
			else l = mid + 1;
		}
		
		if(a[l] == inf) break;
		
		ans = max(ans, T - a[l]);
		
		if(a[l] > T) l = st.begin() -> second;
		
		q.push({l, max(T, a[l])});
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
**/

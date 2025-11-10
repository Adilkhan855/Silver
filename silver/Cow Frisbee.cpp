#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	auto get_res = [](vector<int> a) {
		int n = a.size();
		stack<int> st;
		
		int res = 0;
		
		for(int i = 0; i < n; i++) {
			while(!st.empty() && a[st.top()] < a[i]) st.pop();
			
			if(!st.empty()) {
				res += i - st.top() + 1;
			}
			
			st.push(i);
		}
		
		return res;
	};
	
	int ans = 0;
	ans += get_res(a);
	reverse(all(a));
	ans += get_res(a);
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

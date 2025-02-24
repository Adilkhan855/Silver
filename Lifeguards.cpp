#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

signed main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<pair<int, int>> e;
	
	for(int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		e.emplace_back(l, i);
		e.emplace_back(r, i);
	}
	
	sort(all(e));
	
	set<int> st;
	
	int tot = 0, last = 0;
	
	vector<int> alone(n);
	
	for(auto out : e) {
		if((int)st.size() == 1) {
			alone[*st.begin()] += out.first - last;
		}
		if(!st.empty()) {
			tot += out.first - last;
		}
		if(st.count(out.second)) st.erase(out.second);
		else st.emplace(out.second);
		
		last = out.first;
	}
	
	int ans = 0;
	
	for(auto x : alone) ans = max(ans, tot - x);
	
	cout << ans << nl;
}

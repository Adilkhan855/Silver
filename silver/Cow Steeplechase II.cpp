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

double cur_x;

struct pt { int x, y; int idx; };
struct Seg { pt p, q; int idx; };

pt operator - (pt &a, pt &b) {
	return {a.x - b.x, a.y - b.y};
}

int sign(int x) {
	if(x == 0) return 0;
	return x > 0 ? 1 : -1;
}

int operator * (pt a, pt b) {
	return sign(a.x * b.y - a.y * b.x);
}

bool operator < (pt a, pt b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

bool is(Seg a, Seg b) {
	return ((a.q - a.p) * (b.p - a.p)) * ((a.q - a.p) * (b.q - a.p)) <= 0 && 
			((b.q - b.p) * (a.p - b.p)) * ((b.q - b.p) * (a.q - b.p)) <= 0;
}

double eval(Seg s) {
	if(s.q.x == s.p.x) return s.p.y;
	return s.p.y + (s.q.y - s.p.y) * (cur_x - s.p.x) / (s.q.x - s.p.x);
}

bool operator < (Seg a, Seg b) {
	return a.idx != b.idx && eval(a) < eval(b);
}

bool operator == (Seg a, Seg b) {
	return a.idx == b.idx;
}

void solve() {
	setIO("cowjump");
	int n; cin >> n;
	
	vector<Seg> S(n);
	vector<pt> P(2 * n);
	
	for(int i = 0; i < n; i++) {
		cin >> S[i].p.x >> S[i].p.y >> S[i].q.x >> S[i].q.y;
		S[i].idx = S[i].p.idx = S[i].q.idx = i;
		P[i << 1] = S[i].p;
		P[i << 1 | 1] = S[i].q;
	}
	
	set<Seg> st;
	
	sort(all(P));
	
	int idx1 = -1, idx2 = -1;
	
	for(int i = 0; i < 2 * n; i++) {
		idx1 = P[i].idx; cur_x = P[i].x;
		auto it = st.find(S[idx1]);
		if(it != st.end()) {
			st.erase(it);
		} else {
			auto it2 = st.lower_bound(S[idx1]);
			if(it2 != st.end()) {
				idx2 = it2 -> idx;
				if(is(S[idx2], S[idx1])) break;
			}
			if(it2 != st.begin()) {
				it2--;
				idx2 = it2 -> idx;
				if(is(S[idx2], S[idx1])) break;
			}
			st.insert(S[idx1]);
		}
	}
	
	if(idx1 > idx2) swap(idx1, idx2);
	
	int cnt2 = 0;
	for(int i = 0; i < n; i++) {
		if(i != idx1 && i != idx2 && is(S[i], S[idx2])) cnt2++;
	}
	
	cout << (cnt2 ? idx2 : idx1) + 1 << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

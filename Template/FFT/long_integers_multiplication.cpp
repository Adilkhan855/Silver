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

struct cmpl {
	double x, y;
	
	cmpl(double x = 0, double y = 0) : x(x), y(y) {}
	
	cmpl operator+(const cmpl &other) const {
		return cmpl(x + other.x, y + other.y);
	}
	
	cmpl operator-(const cmpl &other) const {
		return cmpl(x - other.x, y - other.y);
	}
	
	cmpl operator*(const cmpl &other) const {
		return cmpl(x * other.x - y * other.y, x * other.y + y * other.x);
	}
	
	cmpl operator/(const double &u) const {
		return cmpl(x / u, y / u);
	}
	
	double &real() {
		return x;
	}
	
	double &imag() {
		return y;
	}
};

const double PI = atan2(0, -1);

vector<vector<cmpl>> w;

void precalc_roots(int logn) {
	w.resize(logn + 1);
	w[0].resize(1, 1);
	for(int l = 1; l <= logn; l++) {
		int n = (1 << l);
		w[l].resize(n >> 1);
		cmpl the_w(cos(2 * PI / n), sin(2 * PI / n));
		for(int j = 0; j < (n >> 1); j++) {
			w[l][j] = w[l - 1][j >> 1] * (j & 1 ? the_w : 1);
		}
	}
}

void fft(vector<cmpl> &P, bool inv = false) {
	int n = P.size(), logn = 0;
	
	while((1 << logn) < n) logn++;
	
	vector<int> bit_rev(n);
	
	for(int i = 1; i < n; i++) {
		bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (logn - 1));
		if(i < bit_rev[i]) {
			swap(P[i], P[bit_rev[i]]);
		}
	}
	
	for(int l = 1; l <= logn; l++) {
		int len = (1 << l);
		for(int st = 0; st < n; st += len) {
			for(int j = 0; j < (len >> 1); j++) {
				cmpl val1 = P[st + j];
				cmpl val2 = w[l][j] * P[st + (len >> 1) + j];
				P[st + j] = val1 + val2;
				P[st + (len >> 1) + j] = val1 - val2;
			}
		}
	}
	
	if(inv) {
		reverse(P.begin() + 1, P.end());
		for(int i = 0; i < n; i++) {
			P[i] = P[i] / n;
		}
	}
}

vector<int> multiply(const vector<int> &P, const vector<int> &Q) {
	int n = 1, logn = 0;
	
	while(n < (int)(P.size() + Q.size() - 1)) {
		n <<= 1;
		logn++;
	}
	
	precalc_roots(logn);
	
	vector<cmpl> A(n);
	
	for(int i = 0; i < n; i++) {
		A[i] = cmpl(i < (int)P.size() ? P[i] : 0, i < (int)Q.size() ? Q[i] : 0);
	}
	
	fft(A);
	
	for(int i = 0; i < n; i++) {
		A[i] = A[i] * A[i];
	}
	
	fft(A, true);
	
	vector<int> R(n);
	
	for(int i = 0; i < n; i++) {
		R[i] = round(A[i].imag() / 2);
	}
	
	return R;
}

void solve() {
	string s, t; cin >> s >> t;
	
	int sign = 0;
	
	reverse(all(s));
	reverse(all(t));
	
	if(s.back() == '-') {
		sign ^= 1;
		s.pop_back();
	}
	
	if(t.back() == '-') {
		sign ^= 1;
		t.pop_back();
	}
	
	int n = s.size(), m = t.size();
	
	vector<int> P(n), Q(m);
	
	for(int i = 0; i < n; i++) {
		P[i] = s[i] - '0';
	}
	
	for(int i = 0; i < m; i++) {
		Q[i] = t[i] - '0';
	}
	
	auto R = multiply(P, Q);
	
	int i = 0;
	
	while(i < (int)R.size()) {
		int v = R[i] / 10;
		R[i] %= 10;
		if(i + 1 == (int)R.size()) {
			if(v) R.pb(v);
		} else {
			R[i + 1] += v;
		}
		i++;
	}
	
	while(R.size() > 1 && R.back() == 0) R.pop_back();
	
	reverse(all(R));
	
	if(sign && R != vector<int>{0}) cout << '-';
	
	for(auto &x : R) cout << x;
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}

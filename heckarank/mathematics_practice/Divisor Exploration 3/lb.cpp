#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

const int N = 3333;
int C[N][N];

vector<int> primes;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

void solve() {
	int m = nxt(), a = nxt(), d = nxt();
	if (d == 1) {
		long long res = 1;
		for (int i = 0; i < m; ++i) {
			res = res * pw(primes[i], a + i + 1) % mod;
		}
		cout << res % mod << "\n";
		return;
	}
	d -= 2;

	long long res = 1;
	for (int i = 0; i < m; ++i) {
		long long tmp = 0;
		long long cur = 1;
		for (int j = 0; j <= a + i + 1; ++j) {
			tmp += cur * C[a + i + 1 - j + d][d] % mod;
			cur = cur * primes[i] % mod;
		}
		res = res * (tmp % mod) % mod;
	}
	cout << res << "\n";
}

int main() {
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}

	primes = {2};
	for (int i = 3; primes.size() < N / 3; i += 2) {
		if (is_prime(i)) {
			primes.push_back(i);
		}
	}

	int q = nxt();
	while (q--) {
		solve();
	}

	return 0;
}

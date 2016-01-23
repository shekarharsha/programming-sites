#include <iostream>

using namespace std;

typedef unsigned long long ULL;

ULL evaluatePolynomial(int A, int B, int C, ULL x) {
	return ((A*x*x) + B*x + C);
}

int main() {
	
	ios::sync_with_stdio(false);

	int A = 0, B = 0, C = 0;
	ULL K = 0;
	int t = 0;
	cin >> t;

	while (t--) {
		cin >> A >> B >> C >> K;

		if (K <= C) {
			cout << 0 << endl;
			continue;
		}

		ULL low = 0;
		ULL high = K;

		while (high - low > 1) {
			ULL mid = (low + high) / 2;

			ULL value = evaluatePolynomial(A, B, C, mid);
			if (value >= K) {
				high = mid;
			} else {
				low = mid;
			}
		}

		if (evaluatePolynomial(A, B, C, low) == K) {
			cout << low << endl;
		} else {
			cout << high << endl;
		}
	}

	return 0;
}
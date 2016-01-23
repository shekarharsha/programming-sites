#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

void swap(ULL &a, ULL &b) {
	ULL temp = a;
	a = b;
	b = temp;
}

ULL gcd(ULL a, ULL b) {
	if (b > a) {
		swap(a, b);
	}

	ULL temp = 0;
	while ((temp = a % b) != 0) {
		a = b;
		b = temp;
	}

	return b;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int t = 0;
	cin >> t;
	while (t--) {
		ULL l = 0, b = 0;
		cin >> l >> b;
		ULL hcf = gcd(l, b);

		cout << ((l*b) / (hcf*hcf)) << endl;
	}
	return 0;
}
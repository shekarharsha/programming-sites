#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ULL;

ULL iterExpMod(ULL a, int b, int mod) {
	ULL prod = a;
	while (b != 0) {
		if (b % 2 == 1) {
			prod = (prod * a) % mod;
		}
		a = (a*a) % mod;
		b = b / 2;
	}

	return prod;
}

int main()
{
	ios::sync_with_stdio(false);

	ULL A = 0, B = 0;	
	cin >> A >> B;

	string inp;
	cin >> inp;

	ULL sum = 0;
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] == '0') {
			continue;
		}
		else {
			if (i == 0) {
				sum = (sum + (A % B)) % B;
			}
			else {
				sum = (sum + iterExpMod((A*A), i, B)) % B;
			}
		}
	}

	cout << sum << endl;

	return 0;
}
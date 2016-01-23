#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	freopen("andproduct.txt", "r", stdin);

	ios::sync_with_stdio(false);
	int t = 0;
	cin >> t;

	while (t--) {
		unsigned long long a = 0, b = 0;
		cin >> a >> b;

		unsigned long long ans = a;
		for (int i = a + 1; i <= b; i++) {
			ans = ans & i;
		}

		cout << ans << endl;
	}
	return 0;
}

#include <iostream>

using namespace std;

typedef unsigned long long ULL;

int main()
{
	ios::sync_with_stdio(false);
	freopen("codemonkarrays3.txt", "r", stdin);

	int t = 0;
	cin >> t;

	while (t--) {
		ULL N = 0, X = 0;
		cin >> N >> X;

		ULL *inp = new ULL[N];
		int *hash = new int[X]();

		for (ULL i = 0; i < N; i++) {
			cin >> inp[i];
		}

		bool isAllElementsBiggerThanX = true;
		for (int i = 0; i < N; i++) {
			if (inp[i] <= X) {
				isAllElementsBiggerThanX = false;
			}
		}

		bool isPossible = false;
		if (!isAllElementsBiggerThanX) {
			ULL sum = inp[0];
			hash[sum % X] = 1;

			for (ULL i = 1; i < N; i++) {
				sum += inp[i];
				if (hash[sum % X] == 1) {
					isPossible = true;
					break;
				}
				else {
					hash[sum % X] = 1;
				}
			}
		}

		if (isPossible || hash[0] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		/* Delete */
		delete[] hash;
		delete[] inp;
	}

	return 0;
}
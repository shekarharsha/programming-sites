#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	int *arr = new int[N];

	int inversionCount = 0;
	pair<int, int> firstInversion;
	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];

		if (arr[i] < arr[i - 1]) {
			inversionCount++;
			if (inversionCount == 1) {
				firstInversion = make_pair(i - 1, i);
			}
		}
	}

	if (inversionCount == 0) {
		cout << "yes" << endl;
		return 0;
	}
	else if (inversionCount == 1) {
		cout << "yes" << endl << "swap" << " " << firstInversion.first + 1 << " " << firstInversion.second + 1 << endl;
		return 0;
	}

	/* Check for reversal */
	int i = firstInversion.second + 1;
	while (i < N && arr[i] < arr[i-1]) {
		i++;
	}

	if (i == N) {

	}

	return 0;
}

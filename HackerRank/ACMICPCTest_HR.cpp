#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get1s(string &a, string &b) {
	int num1s = 0;
	for (int i = 0; i < a.length(); i++) {
		/* First do bitwise OR and then count the number of 1s */
		if (((a[i] | b[i]) - '0') == 1) {
			num1s++;
		}
	}

	return num1s;
}

int main()
{

	ios::sync_with_stdio(false);
	freopen("acmicpc_hr.txt", "r", stdin);

	int N = 0, M = 0;

	cin >> N >> M;

	vector<string> inp(N);

	for (int i = 0; i < N; i++) {
		cin >> inp[i];
	}

	int max1s = 0;
	int corrMaxPairs = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int num1s = get1s(inp[i], inp[j]);
			if (num1s > max1s) {
				max1s = num1s;
				corrMaxPairs = 1;
			} else if (num1s == max1s) {
				corrMaxPairs++;
			}
		}
	}

	cout << max1s << endl;
	cout << corrMaxPairs << endl;

	return 0;
}
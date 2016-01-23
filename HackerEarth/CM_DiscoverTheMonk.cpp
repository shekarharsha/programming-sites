#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int N = 0, Q = 0;
	cin >> N >> Q;

	vector<int> inp(N);
	for (int i = 0; i < N; i++) {
		cin >> inp[i];
	}

	sort(inp.begin(), inp.end());

	int search = 0;
	for (int i = 0; i < Q; i++) {
		cin >> search;
		if (binary_search(inp.begin(), inp.end(), search)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
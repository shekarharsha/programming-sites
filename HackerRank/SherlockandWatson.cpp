#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ios::sync_with_stdio(false);

	freopen("sherlock_watson.txt", "r", stdin);

	int N, K, Q;
	cin >> N >> K >> Q;

	deque<int> deq;
	int value;
	for (int i = 0; i < N; i++) {
		cin >> value;
		deq.push_back(value);
	}

	if (K > N) {
		K = K % N;
	}

	for (int i = 0; i < K; i++) {
		int e = deq.back();
		deq.pop_back();
		deq.push_front(e);
	}

	int idx = 0;
	for (int i = 0; i < Q; i++) {
		cin >> idx;
		cout << deq[idx] << endl;
	}

	return 0;
}

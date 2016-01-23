#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ios::sync_with_stdio(false);
	int N = 0;
	cin >> N;

	vector<int> inp(N);
	for (int i = 0; i < N; i++) {
		cin >> inp[i];
	}

	sort(inp.begin(), inp.end());

	vector<pair<int, int>> answer;
	int minDiff = INT_MAX;

	for (int i = 1; i < N; i++) {
		if ((inp[i] - inp[i - 1]) == minDiff) {
			answer.push_back(make_pair(inp[i - 1], inp[i]));
		}
		else if ((inp[i] - inp[i - 1]) < minDiff) {
			answer.clear();
			minDiff = (inp[i] - inp[i - 1]);
			answer.push_back(make_pair(inp[i - 1], inp[i]));
		}
		else {
			continue;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << " ";
	}

	cout << endl;

	return 0;
}

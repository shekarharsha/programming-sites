#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

typedef unsigned long long ULL;

int main() {
	ios::sync_with_stdio(false);

	freopen("codemonkstl1.txt", "r", stdin);

	int t = 0;
	cin >> t;
	while (t--) {
		int N = 0, M = 0;
		cin >> N >> M;

		unordered_map<ULL, bool> candies;
		ULL candy = 0;
		for (int i = 0; i < (N + M); i++) {
			cin >> candy;
			if (i < N) {
				candies.insert(make_pair(candy, true));
				continue;
			}

			if (candies.find(candy) == candies.end()) {
				cout << "NO" << endl;
				candies.insert(make_pair(candy, true));
			}
			else {
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	freopen("he_projectteam.txt", "r", stdin);

	int t = 0;
	cin >> t;

	while (t--) {
		int N = 0;
		cin >> N;

		vector<int> inp(N);
		for (int i = 0; i < N; i++) {
			cin >> inp[i];
		}

		sort(inp.begin(), inp.end());

		vector<int> teamStrength;
		for (int i = 0; i < N / 2; i++) {
			teamStrength.push_back(inp[i] + inp[N - 1 - i]);
		}
		sort(teamStrength.begin(), teamStrength.end());

		cout << (teamStrength[teamStrength.size() - 1] - teamStrength[0]) << endl;
	}

	return 0;
}
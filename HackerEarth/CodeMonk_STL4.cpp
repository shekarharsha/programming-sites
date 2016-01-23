#include <iostream>
#include <queue>
#include <functional>

using namespace std;

typedef unsigned long long ULL;

int main()
{
	ios::sync_with_stdio(false);

	freopen("codemonkstl4.txt", "r", stdin);

	int t = 0;
	cin >> t;

	while (t--) {
		int N = 0, K = 0;
		cin >> N >> K;

		priority_queue<ULL, vector<ULL>, less<ULL>> pq;
		ULL candies = 0;
		for (int i = 0; i < N; i++) {
			cin >> candies;
			pq.push(candies);
		}

		ULL sum = 0;
		for (int i = 0; i < K; i++) {
			ULL value = pq.top();
			pq.pop();
			sum += value;
			value = value / 2;
			pq.push(value);
		}

		cout << sum << endl;		
	}

	return 0;
}
#include <iostream>

using namespace std;

typedef long long LL;

class QuickUnion {
	int *id;

	int findRoot(int i) {
		while (id[i] != i) {
			i = id[i];
		}
		return i;
	}

public:

	int *size;

	QuickUnion(int N) {
		id = new int[N];
		size = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			size[i] = 1;
		}
	}

	bool isConnected(int p, int	q) {
		return (findRoot(p) == findRoot(q));
	}

	void connect(int p, int q) {
		int i = findRoot(p);
		int j = findRoot(q);

		if (i != j) {
			if (size[i] >= size[j]) {
				id[j] = i;
				size[i] += size[j];
				size[j] = 0;
			}
			else {
				id[i] = j;
				size[j] += size[i];
				size[i] = 0;
			}
		}
	}

};


int main()
{

	ios::sync_with_stdio(false);
	freopen("journeytomoon.txt", "r", stdin);

	LL N = 0, I = 0;
	cin >> N >> I;

	QuickUnion qu(N);
	int node1 = 0, node2 = 0;
	for (int i = 0; i < I; i++) {
		cin >> node1 >> node2;
		qu.connect(node1, node2);
	}

	LL totalPairs = (N * (N - 1)) / 2;
	LL individualGroupPairs = 0;
	for (int i = 0; i < N; i++) {
		if (qu.size[i] == 1 || qu.size[i] == 0) {
			continue;
		}
		else {
			individualGroupPairs += (qu.size[i] * (qu.size[i] - 1)) / 2;
		}
	}

	LL finalPairs = totalPairs - individualGroupPairs;

	cout << finalPairs << endl;

	return 0;
}
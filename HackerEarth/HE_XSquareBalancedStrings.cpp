#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t = 0;
	cin >> t;

	while (t--) {
		string inp;
		cin >> inp;
		
		int count[26] = { 0, };

		for (int i = 0; i < inp.size(); i++) {
			count[inp[i] - 'a']++;
		}

		int i = 0;
		for (; i < 26; i++) {
			if (count[i] % 2 != 0) {
				break;
			}
		}

		if (i != 26) {
			cout << -1 << endl;
		} else {
			cout << 1 << endl;
		}
	}

	return 0;
}
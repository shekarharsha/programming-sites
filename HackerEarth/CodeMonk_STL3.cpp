#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	freopen("codemonkstl3.txt", "r", stdin);

	int N = 0;
	cin >> N;

	string name = "";
	int marks = 0;

	map<int, vector<string>> studentMarks;

	while (N--) {
		cin >> name >> marks;
		studentMarks[marks].push_back(name);
	}

	map<int, vector<string>>::reverse_iterator it;
	for (it = studentMarks.rbegin(); it != studentMarks.rend(); it++) {
		if (((*it).second).size() > 1) {
			vector<string> names = (*it).second;
			sort(names.begin(), names.end());
			for (int i = 0; i < names.size(); i++) {
				cout << names[i] << " " << (*it).first << endl;
			}
		}
		else {
			cout << ((*it).second)[0] << " " << (*it).first << endl;
		}
	}
	return 0;
}
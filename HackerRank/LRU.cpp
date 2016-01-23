#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {

	int currSize;
public:

	LRUCache(int capacity) {
		cp = capacity;
		head = NULL;
		tail = NULL;
		currSize = 0;
	}

	void set(int key, int value) {
		if (get(key) == -1) {
			Node *temp = new Node(key, value);
			if (head == NULL) {
				head = tail = temp;
			}
			else {
				temp->next = head;
				head->prev = temp;
				head = temp;
			}
			mp[key] = temp;
			currSize++;

			if (currSize > cp) {
				/* Remove the last node */
				currSize = cp;
				Node *temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				temp->prev = NULL;

				delete(temp);
			}
		} else {
			Node *temp = mp[key];
			temp->value = value;
		}
	}

	int get(int key) {
		if (mp.find(key) != mp.end()) {
			/* key present - move to the head of the list */
			Node *temp = mp[key];

			if (temp == head) {
				/* Do nothing */
			} else if (temp == tail) {
				Node *prev = temp->prev;

				prev->next = NULL;
				tail = prev;

				temp->next = head;
				temp->prev = NULL;

				head->prev = temp;
				head = temp;
			} else {
				Node *next = temp->next;
				Node *prev = temp->prev;

				prev->next = next;
				next->prev = prev;

				temp->next = head;
				temp->prev = NULL;

				head->prev = temp;
				head = temp;
			}
			return temp->value;
		} else {
			return -1;
		}
	}
};


int main() {

	ios::sync_with_stdio(false);

	freopen("lru.txt", "r", stdin);

	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i<n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}
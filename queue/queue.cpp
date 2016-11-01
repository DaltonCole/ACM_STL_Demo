// http://www.cplusplus.com/reference/queue/queue/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;

	// Push 0-9 onto the queue
	for(int i = 0; i < 10; i++) {
		q.push(i);
	}

	// Print front element
	cout << "Front: \t" << q.front() << endl;

	// Print back element
	cout << "Back: \t" << q.back() << endl;

	// Empty?
	cout << "Empty?: \t" << q.empty() << endl;

	queue<int> p;

	// Swap q and p
	p.swap(q);

	// Pop while not empty
	while(!p.empty()) {
		cout << p.front() << endl;
		p.pop();
	}

	return 0;
}
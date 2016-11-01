#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
using namespace std;

void print(vector<int> v) {
	for(auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

void print(deque<int> v) {
	for(auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v;

	for(int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	auto it = v.begin();

	// Advance
	advance(it, 5); // Could be negative
	cout << "advance: \t" << *it << endl;

	// Distance
	cout << "distance: \t" << distance(v.begin(), v.end()) << endl;

	// Next - Returns an iterator as if advanced was applied
	cout << "next(it,2): \t" << *next(it, 2) << endl;

	// Prev - Returns an iterator as if -advanced was applied
	cout << "prev(it,4): \t" << *prev(it, 4) << endl;

	// back_inserter - acts like push_back
	vector<int> u;
	for(int i = 0; i < 10; i++) {
		u.push_back(i*10);
	}
	copy(v.begin(), v.end(), back_inserter(u)); // Adds contents of v to the end of u
	print(u);

	// front_inserter - acts like push_front, use list or deque
	deque<int> d, e;
	for(int i = 0; i < 10; i++) {
		d.push_back(i);
		e.push_back(i*i);
	}
	copy(d.begin(), d.end(), front_inserter(e)); // Adds contents of d to the begining of e
	cout << "front_inserter: ";
	print(e);

	// inserter - inserts v into u at it + x position
	u = v;
	it = u.begin();
	advance(it, 4);
	copy(v.begin(), v.end(), inserter(u, it));
	cout << "inserter: \t";
	print(u);





	return 0;
}
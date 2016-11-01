// More info: http://www.cplusplus.com/reference/deque/deque/

// Double Ended QUEue
// Pronounced "deck"
// Compile with "g++ -std=c++11 deque.cpp"
#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> d; 									// Empty deque
	deque<int> second(10, 0);						// Put 10 zeros in second
	deque<int> third(second.begin(), second.end());	// Iterate through second
	deque<int> fourth(third);						// fourth = third

	for(int i = 9; i >= 0; i--) {
		d.push_front(i);
		d.push_back(i);
	}

	cout << "Printing d: \t" << endl;
	for(auto it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Clear
	cout << "second size before clear: \t" << second.size() << endl;
	second.clear();
	cout << "second size after clear: \t" << second.size() << endl;

	// assign
	auto iterator = d.begin();

	second.assign(iterator, d.end());

	cout << "Printing second after assign(): \t" << endl;
	for(auto it = second.begin(); it != second.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// at
	cout << "d.at(4): \t" << d.at(4) << endl;

	// back
	cout << "d.back(): \t" << d.back() << endl;

	// erase the first 3 elements:
	d.erase (d.begin(),d.begin()+3);
	cout << "Erase first three elemetns of d: \t" << endl;
	for(auto it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// front
	cout << "d.front(): \t" << d.front() << endl;

	// insert
	iterator = d.begin();
	d.insert(iterator + 3, 10);
	cout << "Insert 10 into d at 4th position: " << endl;
	for(auto it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// pop_back
	d.pop_back();
	cout << "d after pop_back():" << endl;
	for(auto it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// pop_front
	d.pop_front();
	cout << "d after pop_front():" << endl;
	for(auto it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
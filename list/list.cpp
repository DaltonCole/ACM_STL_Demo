// More info: http://www.cplusplus.com/reference/list/list/

// Doubly-Linked Lists 
// Compile: "g++ -std=c++11 list.cpp"

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

bool greater_than_30(const int & i) {
	return (i > 30);
}

struct is_odd {
	bool operator()(const int & i) {
		return ((i % 2) == 1);
	}
};

int main() {
	list<int> l1;
	list<int> l2(3, 1); // 3 ints all valued 1
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l3);

	// Push Back
	for(int i = 0; i < 10; i++) {
		l1.push_back(pow(i,2));
	}

	// Print
	cout << "\t \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Insert - uses an iterator
	list<int>::iterator it = l1.begin();
	it++;

	l1.insert(it, 12);		// Insert 12 before where it points to
	l1.insert(it, 2, 3); 	// Insert 2 three
	l1.insert(it, -7);

	cout << "Insert: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Back
	cout << "Back: \t \t" << l1.back() << endl;

	// Emplace
	it++;
	l1.emplace(it, 45);
	l1.emplace_front(214);
	l1.emplace_back(-1);

	cout << "Emplace: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Empty
	cout << "Empty: \t \t" << l1.empty() << endl;

	// Erase
	l1.erase(l1.begin());	// Erases the first element
	l1.erase(it, l1.end());	// Erases from it to l1.end()

	cout << "Erase: \t \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Front
	cout << "Front: \t \t" << l1.front() << endl;

	// Merge
	l1.merge(l2); // Assumes both lists are already ordered, could use custom comparison function

	cout << "Merge: \t \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Pops and pushes
	l1.pop_back();
	l1.pop_front();
	l1.push_front(31);
	l1.push_back(24);

	cout << "Pop and push: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Reverse, using iterators
	cout << "Reverse iter: \t";
	for(auto it2 = l1.rbegin(); it2 != l1.rend(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	// Remove
	l1.remove(1); // Removes all 1s from the list

	cout << "Remove: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Remove if
	l1.remove_if(is_odd());
	l1.remove_if(greater_than_30);

	cout << "Remove_if: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Reverse
	l1.reverse();

	cout << "Reverse: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Size
	cout << "Size: \t \t" << l1.size() << endl;

	// Sort
	l1.sort(); // Could use custom sorting function

	cout << "Sort: \t \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Splice
	auto l5 = l1;
	auto it3 = l1.end();
	it3--;
	l1.splice(it3, l5); // l5 is now empty

	cout << "Splice: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	cout << "l5 is empty?:\t" << l5.empty() << endl;

	// Unique - Only removes elements if they repeat immedetly before hand (ie 5,1,5,5 -> 5,1,5)
	l1.unique();

	cout << "Unique: \t";
	for(auto & i : l1) {
		cout << i << " ";
	}
	cout << endl;

	// Clear
	l1.clear();

	return 0;
}
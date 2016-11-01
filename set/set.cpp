// More info: http://www.cplusplus.com/reference/set/set/

// Compile using "g++ -std=c++11 set.cpp"
#include <iostream>
#include <set>
using namespace std;

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const {
  	// All hail 5!
  	if(lhs == 5) {
  		return true;
  	} 
  	if(rhs == 5) {
  		return false;
  	}
  	return lhs>rhs;
  }
};

int main() {
	set<int> s1;

	set<int,classcomp> s2; // Custom compare function used

	// insert
	for(int i = 0; i < 10; i++) {
		s1.insert(i);
		s2.insert(i);
	}

	// insert again (does nothing)
	for(int i = 0; i < 10; i++) {
		s1.insert(i);
	}

	// Iterate through s1
	cout << "s1: \t \t";
	for(auto i: s1) {
		cout << i << " ";
	}
	cout << endl;

	// Iterate through s2
	cout << "s2: \t \t";
	for(auto i: s2) {
		cout << i << " ";
	}
	cout << endl;

	// find
	auto it = s1.find(3);
	if(it != s1.end()) {
		cout << *it << " exists!" << endl;
	}

	// erase
	// s1.erase(3);
	s1.erase(it);

	cout << "Erased 3: \t";
	for(auto i: s1) {
		cout << i << " ";
	}
	cout << endl;

	// upper_bound and lower_bound
	set<int>::iterator itlow, itup; // How to declare iterator
	itlow = s1.lower_bound(5);
	itup = s1.upper_bound(8);
	s1.erase(itlow, itup);

	cout << "Erased 5-8: \t";
	for(auto i: s1) {
		cout << i << " ";
	}
	cout << endl;

	// Reverse
	cout << "Reverse: \t";
	set<int>::reverse_iterator it2;
	for(it2 = s1.rbegin(); it2 != s1.rend(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	// emplace_hint - inserts i at the proper position
	cout << "Emplace hint: \t";
	auto it3 = s1.begin();
	it3 = s1.emplace_hint(it3, 3); // Returns an iterator at the position where 3 is placed
	for(auto i: s1) {
		cout << i << " ";
	}
	cout << endl;

	// count - will return at most 1
	cout << "Count: \t \t" << s1.count(4) << endl;

	return 0;
}
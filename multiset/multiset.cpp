// More info: http://www.cplusplus.com/reference/set/multiset/

// Pretty much the same as set, but can have more than 1 of the same item
// Compile using "g++ -std=c++11 multiset.cpp"
#include <iostream>
#include <set>
using namespace std;

int main() {
	multiset<int> s1;

	// insert
	for(int i = 0; i < 10; i++) {
		s1.insert(i);
		s1.insert(i);
		s1.insert(i);
	}

	// count
	cout << "Count: \t \t" << s1.count(4) << endl;

	return 0;
}
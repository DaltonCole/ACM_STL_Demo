// More info: http://www.cplusplus.com/reference/unordered_set/unordered_multiset/unordered_multiset/

// Basically the same as unordered_set, but can contain multiple of the same value
// Combile with "g++ -std=c++11 unordered_set.cpp "
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {


	unordered_multiset<int> us;

	// Insert
	us.insert(4);
	us.insert(1);
	us.insert(2);
	us.insert(3);
	us.insert(1); 

	// count
	cout << "Count of 2's: " << us.count(2) << endl;
	cout << "Count of 1's: " << us.count(1) << endl; 


	return 0;
}
// More info: http://www.cplusplus.com/reference/unordered_set/unordered_set/

// Unordered_set was introducted in c++ 11
// It contains unique elements only, much like a set
// Stores elements using a hash table
// Combile with "g++ -std=c++11 unordered_set.cpp "
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	// Possible constructors
	/*
	std::unordered_set<std::string> first;                                // empty
    std::unordered_set<std::string> second ( {"red","green","blue"} );    // init list
    std::unordered_set<std::string> third ( {"orange","pink","yellow"} ); // init list
    std::unordered_set<std::string> fourth ( second );                    // copy
    std::unordered_set<std::string> fifth ( cmerge(third,fourth) );       // move
    std::unordered_set<std::string> sixth ( fifth.begin(), fifth.end() ); // range
  */

	unordered_set<int> us;

	// Insert
	us.insert(4);
	us.insert(1);
	us.insert(2);
	us.insert(3);
	us.insert(1); // Won't change anything

	for(const int & s : us) { // range based for loop: http://en.cppreference.com/w/cpp/language/range-for
		cout << s << " ";
	}
	cout << endl;

	// Find
	auto const_it = us.find(3); // Constant iterator
	// Will point to the 
	if(const_it == us.end()) {
		cout << "3 is not in us" << endl;
	} else {
		cout << *const_it << " is in us" << endl;
	}

	// Erase
	us.erase(1);
	cout << "Removed 1" << endl;
	for (int s : us) {
		cout << s << " ";
	}
	cout << endl;

	// hash_function
	cout << "Hash function: ";
	unordered_set<string> strings ({"blue", "red", "green"});
	auto hash = strings.hash_function();
	cout << hash("blue") << endl;

	// count (Returns at most 1)
	cout << "Count of 2's: " << us.count(2) << endl;
	cout << "Count of 1's: " << us.count(1) << endl; 


	return 0;
}
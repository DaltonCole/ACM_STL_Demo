// More Info: http://www.cplusplus.com/reference/vector/vector/

// Vectors are sequence containers representing arrays that can change in size.
// Compile with "g++ -std=c++11 vector.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Notice how you use it just like a template
	vector<int> v; 			// Empty vector
	vector<int> t(10, 0);	// Fills t with 10 Zeros

	// Auto, just so you know it exists
	auto a = t;
	// Auto automatically detects the type

	for(int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	// v now has 10 elements ranging from 0 to 9

	// Equal operator
	t = v;

	// Print 0-9 using normal for loop
	cout << "Printing 0-9 using normal for loop: \t";
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	// Swap the contents of v with a and a with v (they can be of different sizes)
	v.swap(a);

	// Print 10 Zeros using an iterator (because we swapped v and a)
	cout << endl << "Printing v using an iterator: \t";
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl << endl;

	// Cool functions
	cout << "Max Size: \t" << v.max_size() << endl;	// Maximum number of elements v can hold due to system limitations
	cout << "Capacity: \t" << v.capacity() << endl;	// Size of storage space v currently holds (can be different from size())
	cout << "Size: \t" << v.size() << endl;			// Size of v

	// Resizing vectors
	a.resize(5);
	cout << endl << "Size of a after resize(5): \t" << a.size() << endl;
	cout << "Capacity of a: \t" << a.capacity() << endl;
	a.shrink_to_fit();
	cout << "Capacity of a after shrink_to_fit(): \t" << a.capacity() << endl;

	cout << "Printing new a: \t";
	for(vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "Pop_back a: \t";
	a.pop_back();
	for(vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl << endl;

	// Erase the 6th element from t
	t.erase(t.begin()+5); // iterator erase (iterator position);
	// Erase the 7th element to the end of t
	t.erase(t.begin()+6, t.end());
	cout << endl << "Printing t after erase(): \t";
	for(vector<int>::iterator it = t.begin(); it != t.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl << endl;

	// cr = const_reverse_iterator
	cout << endl << "Printing t... reversed :D \t";
	for(auto it = t.crbegin(); it != t.crend(); ++it) {
		cout << *it << " ";
	}
	cout << endl << endl;

	// Is empty?
	cout << "Is t empty?: \t" << t.empty() << endl; 

	return 0;
}
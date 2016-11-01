#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	bitset<8> a("1001001");

	cout << "\t" << a << endl;

	// []
	cout << "[]: \t" << a[5] << endl;

	// count - counts the number of 1s
	cout << "count: \t" << a.count() << endl;

	// size
	cout << "size: \t" << a.size() << endl;

	// test - returns bit value
	cout << "test: \t" << a.test(5) << endl;

	// any - test if any bit is set
	cout << "any: \t" << a.any() << endl;

	// none - test no bits are set
	cout << "none: \t" << a.any() << endl;

	// all - test if all bits are set
	cout << "all: \t" << a.all() << endl;

	// set - set a bit
	cout << "set: \t" << a.set(5) << endl; 

	// reset - turn a bit to 0
	cout << "reset: \t" << a.reset(5) << endl;

	// flip - flips a bit
	cout << "flip: \t" << a.flip(5) << endl;

	return 0;
}
#include <iostream>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> fl;

	// Assign
	fl.assign(2, 5); // [5, 5]

	// Push front
	for(int i = 0; i < 10; i++) {
		fl.push_front(i);
	}

	// Emplace
	auto it = fl.begin();
	fl.emplace_after(fl.begin(), 6);

	fl.emplace_front(3);

	for(auto i : fl) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
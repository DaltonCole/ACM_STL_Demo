#include <iostream>
#include <vector>
#include <ctime> // More info on ctime: http://www.cplusplus.com/reference/ctime/clock/
using namespace std;

// Iterators can be thought of as limited pointers

// Why iterators?
// http://stackoverflow.com/questions/178934/iterators-why-use-them
// http://stackoverflow.com/questions/131241/why-use-iterators-instead-of-array-indices
// http://www.cprogramming.com/tutorial/stl/iterators.html

// Compile using "g++ -std=c++11 iterator_speed_test.cpp"
int main() {
	clock_t start;

	vector<int> v;

	int temp;

	for(int i = 0; i < 1000000; i++) {
		v.push_back(i);
	}

	cout << "Normal for loop time: " << endl;
	
	start = clock();

	for(int i = 0; i < v.size(); i++) { // .size() is FAST for vector, but not for all containers
		v[i] = 0;
	}

	cout << clock() - start << endl;

	cout << "Normal for loop time (prestore v.size()): " << endl;
	
	start = clock();

	auto q = v.size();
	for(int i = 0; i < q; i++) {
		v[i] = 1;
	}

	cout << clock() - start << endl;

	cout << "Iterator loop time: " << endl;

	start = clock();

	for(auto i = v.begin(); i != v.end(); i++) {
		*i = 2;
	}

	cout << clock() - start << endl;

	cout << "Iterator loop time (prestore v.end()): " << endl;

	start = clock();

	auto u = v.end();
	for(auto i = v.begin(); i != u; i++) {
		*i = 3;
	}

	cout << clock() - start << endl;

	cout << "Ranged based for loop time: " << endl;

	start = clock();

	for(auto &i : v) {
		i = 4;
	}

	cout << clock() - start << endl;

	return 0;
}
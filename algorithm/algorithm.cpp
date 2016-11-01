// More info: http://www.cplusplus.com/reference/algorithm/

// Compile using
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> 	// Random
#include <ctime> 	// Time
using namespace std;

int random_func(const int a = 10, const int b = 0) {
	return (rand() % a) + b;
}

void v_random(vector<int> & a, const int size = 10) {
	a.clear();
	for(int i = 0; i < size; i++) {
		a.push_back(random_func());
	}
	return;
}

void print(const vector<int> & v) {
	for(auto it : v) {
		cout << it << " ";
	}
	cout << endl;
	return;
}

struct myCompare{
	bool operator ()(int a, int b) {
		return a > b;
	}
} myObject;

bool odd_function(int i) {
	return i % 2 == 1;
}

int main() {
	srand(time(0));

	vector<int> v;
	v_random(v);

	// ------------------------------ Sort ------------------------------
	cout << " --------------------- Sort ---------------------" << endl;

	// Sort
	sort(v.begin(), v.end(), myObject); // Begin iterator, end operator, compare function (optional)
	cout << "Sort: \t \t";
	print(v);

	// stable_sort - Like sort, but maintains order of similar values
	v_random(v);
	stable_sort(v.begin(), v.end());
	cout << "stable_sort: \t";
	print(v);

	// partial_sort - Sorts the first x the elements
	v_random(v);
	partial_sort(v.begin(), v.begin() + (v.size()/2), v.end());
	cout << "partial_sort: \t";
	print(v);

	// is_sorted - returns true if the list is sorted
	cout << "is_sorted?: \t" << is_sorted(v.begin(), v.end()) << endl;

	// is_sorted_until - returns an iterator to the first non-sorted element
	v_random(v);
	auto it = is_sorted_until(v.begin(), v.end());
	cout << "is_sorted_until: " << *it << " \t";
	print(v);

	// nth_element - places the nth element where it would normally go, without ordering the rest of the elements in any real order
	// NOTE: everything below nth is less than, everything above nth is greater than
	v_random(v);
	nth_element(v.begin(), v.begin()+3, v.end());
	cout << "nth_element: \t";
	print(v);

	// ------------------------------ Min/ Max ------------------------------
	cout << " --------------------- Min/ Max ---------------------" << endl;
	// Min
	cout << "min(1,5): \t \t" << min(1,5) << endl;
	// Max
	cout << "max(1,5): \t \t" << max(1,5) << endl;
	// minmax - returns min as a and max as b (a = first element, b = second element)
	auto minmaxNumber = minmax({1,2,3,4,5});
	cout << "minmax({1,2,3,4,5})\t" << minmaxNumber.first << " " << minmaxNumber.second << endl;
	// min_element - returns and iterator to the min element
	v_random(v);
	cout << "min_element: \t \t" << *min_element(v.begin(), v.end()) << endl;
	// max_element - returns and iterator to the max element
	cout << "max_element: \t \t" << *max_element(v.begin(), v.end()) << endl;
	// minmax_element - returns an iterator pair to the min and max elements
	auto minmax_elementNumber = minmax_element(v.begin(), v.end());
	cout << "minmax_element: \t" << *minmax_elementNumber.first << " at position " << (minmax_elementNumber.first - v.begin()) << "\t";
	cout << *minmax_elementNumber.second << " at position " << (minmax_elementNumber.second - v.begin()) << "\t Vector: ";
	print(v);

	// ------------------------------ Heap ------------------------------
	cout << " --------------------- Heap ---------------------" << endl;

	// make_heap - max heap by default
	v_random(v);
	make_heap(v.begin(), v.end());
	cout << "make_heap: \t";
	print(v);

	// pop_heap
	pop_heap(v.begin(), v.end()); // Moves largest element to the back
	v.pop_back();
	cout << "pop_heap: \t";
	print(v);

	// push_heap
	v.push_back(31);
	push_heap(v.begin(), v.end());
	cout << "push_heap: \t";
	print(v);

	// sort_heap - sorts from least to greatest, loses heap property
	sort_heap(v.begin(), v.end());
	cout << "sort_heap: \t";
	print(v);

	// is_heap - returns true if container forms a heap, and was created with make_heap
	cout << "is_heap?: \t" << is_heap(v.begin(), v.end()) << endl;

	// is_heap_until - returns an iterator to the first element that does not hold the heap property
	make_heap(v.begin(), v.end());
	cout << "is_heap_until: \t" << is_heap_until(v.begin(), v.end()) - v.begin() << endl;

	// ------------------------------ Merge ------------------------------
	cout << " --------------------- Merge ---------------------" << endl;

	// merge - Combines two ranges
	int first[] = {1, 2, 3, 4, 5};
	int second[] = {7,6,4,3,2};
	v_random(v);
	sort(first, first+5);
	sort(second, second+5);
	merge(first, first+5, second, second+5, v.begin());
	cout << "Merge: \t \t";
	print(v);

	// includes -  Returns true if a contains b
	vector<int> u(3,10);
	vector<int> t(2,10);
	cout << "Includes: \t" << includes(u.begin(), u.end(), t.begin(), t.end()) << endl;

	// set_union - Unions two sets
	sort(first, first+5);
	sort(second, second+5);
	auto it_union = set_union(first, first+5, second, second+5, v.begin());
	v.resize(it_union - v.begin());
	cout << "set_union: \t";
	print(v);

	// set_intersection - Intersect two sets
	sort(first, first+5);
	sort(second, second+5);
	auto it_intersection = set_intersection(first, first+5, second, second+5, v.begin());
	v.resize(it_intersection - v.begin());
	cout << "set_intersection: \t";
	print(v);

	// set_difference - What is in first, but not in the second
	sort(first, first+5);
	sort(second, second+5);
	auto it_difference = set_difference(first, first+5, second, second+5, v.begin());
	v.resize(it_difference - v.begin());
	cout << "set_difference: \t";
	print(v);

	// set_symmetric_difference
	v.resize(10); // Resize to fit everything
	sort(first, first+5);
	sort(second, second+5);
	auto it_symmetric_difference = set_symmetric_difference(first, first+5, second, second+5, v.begin());
	v.resize(it_symmetric_difference - v.begin());
	cout << "set_symmetric_difference: \t";
	print(v);

	/* // Vector way //
	vector<int> a;
	vector<int> b;
	vector<int> c(20);
	v_random(a);
	v_random(b);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	auto it_a = set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	c.resize(it_a - c.begin());
	print(c);
	*/


	// ------------------------------ Binary search ------------------------------
	cout << " --------------------- Binary search ---------------------" << endl;
	// lower_bound - Returns and iterator to the first element greater than the given element (2 in this case)
	v_random(v);
	sort(v.begin(), v.end());
	cout << "\t \t";
	print(v);
	cout << "lower_bound: \t" << lower_bound(v.begin(), v.end(), 2) - v.begin() << endl;
	// upper_bound - Returns and iterator to the first element greater than the given element (7 in this case)
	cout << "upper_bound: \t" << upper_bound(v.begin(), v.end(), 7) - v.begin() << endl;
	// equal_range - Returns an iterator pair of the range of same values
	auto it_equal = equal_range(v.begin(), v.end(), 5);
	cout << "equal_range: \t" << it_equal.first - v.begin() << " - " << it_equal.second - v.begin() << endl;
	// binary_search - Returns true of x is in range
	cout << "binary_search: \t" << binary_search(v.begin(), v.end(), 5) << endl;

	// ------------------------------ Modifying sequence operations: ------------------------------
	cout << " --------------------- Modifying sequence operations: ---------------------" << endl;
	v_random(v);
	cout << "\t \t";
	print(v);
	// random_shuffle
	random_shuffle(v.begin(), v.end());
	cout << "random_shuffle: ";
	print(v);
	// rotate - rotate the elements such that middle becomes the new left
	sort(v.begin(), v.end());
	rotate(v.begin(), v.begin() + 2, v.end());
	cout << "rotate: \t";
	print(v);
	// reverse
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	cout << "reverse: \t";
	print(v);
	// unique
	sort(v.begin(), v.end());
	u = v;
	it = unique(u.begin(), u.end());
	u.resize(distance(u.begin(), it));
	cout << "unique: \t";
	print(u);
	// swap
	swap(v,u);
	cout << "swap: \t \t";
	print(v);
	// copy
	swap(v,u);
	copy(u.begin(), u.end(), v.begin());
	cout << "copy: \t \t";
	print(v);

	// ------------------------------ Non-Modifying sequence operations: ------------------------------
	cout << " --------------------- Non-Modifying sequence operations: ---------------------" << endl;

	v_random(v);
	cout << "\t \t";
	print(v);
	// Note: odd_function returns true if the value is odd
	// all_of - returns true if all of the elements satify the function
	cout << "all_of: \t" << all_of(v.begin(), v.end(), odd_function) << endl;
	// any_of - returns true if any of the elements satify the function
	cout << "any_of: \t" << any_of(v.begin(), v.end(), odd_function) << endl;
	// none_of - opposite of all_of
	cout << "none_of: \t" << none_of(v.begin(), v.end(), odd_function) << endl;
	// find - Returns an iterator to the first element to be equal to the given value
	cout << "find: \t \t" << find(v.begin(), v.end(), 5) - v.begin() << endl;
	// find_if - Returns an iterator to the first value that the function returns true for
	cout << "find_if: \t" << find_if(v.begin(), v.end(), odd_function) - v.begin() << endl;
	// find_if_not
	cout << "find_if_not: \t" << find_if_not(v.begin(), v.end(), odd_function) - v.begin() << endl;
	// adjacent_find - Returns an iterator the first repeated adjacent elements
	cout << "adjacent_find: \t" << adjacent_find(v.begin(), v.end()) - v.begin() << endl;
	// count 
	cout << "count: \t \t" << count(v.begin(), v.end(), 5) << endl;
	// count_if - counts according to a function
	cout << "count_if: \t" << count_if(v.begin(), v.end(), odd_function) << endl;
	// equal - Returns true if the range v.start to v.end and u.start... are equal
	u = v;
	cout << "equal: \t \t" << equal(v.begin(), v.end(), u.begin()) << endl;
	// search - Returns an iterator to the first element in v that all of u is in
	int array1[] = {0, 1};
	cout << "search: \t" << search(v.begin(), v.end(), array1, array1+2) - v.begin() << endl;

	return 0;
}
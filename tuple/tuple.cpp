#include <iostream>
#include <tuple>
using namespace std;

int main() {
	tuple<int, char> a(12, 'b');

	// make_tuple
	auto t = make_tuple(1, 5, 3.5, "hi", 'b', 'y', 'e');

	// get
	cout << "get: \t" << get<3>(t) << endl;

	// tie
	int x;
	char y;
	tie(x, ignore, ignore, ignore, ignore, y, ignore) = t;
	cout << "tie: \t" << x << " " << y << endl;

	// tuple_cat
	auto cat = tuple_cat(t, a);
	cout << "cat: \t";
	cout << get<0>(cat) << " ";
	cout << get<1>(cat) << " ";
	cout << get<2>(cat) << " ";
	cout << get<3>(cat) << " ";
	cout << get<4>(cat) << " ";
	cout << get<5>(cat) << " ";
	cout << get<6>(cat) << " ";
	cout << get<7>(cat) << " ";
	cout << get<8>(cat) << " ";
	cout << endl;


	return 0;
}
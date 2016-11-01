#include <iostream>
#include <ratio>
using namespace std;

int main() {
	typedef ratio<1, 3> oneThird;
	typedef ratio<1, 2> half;

	// ratio_add
	typedef ratio_add<oneThird, half> sum;
	cout << "ratio_add: \t \t" << sum::num << " / " << sum::den << endl; 

	// ratio_divide
	typedef ratio_divide<oneThird, half> divide;
	cout << "ratio_divide: \t \t" << divide::num << " / " << divide::den << endl;

	// ratio_equal
	cout << "ratio_equal: \t \t" << ratio_equal<oneThird, half>::value << endl;

	// ratio_greater
	cout << "ratio_greater: \t \t" << ratio_greater<oneThird, half>::value << endl;

	// ratio_greater_equal
	cout << "ratio_greater_equal: \t" << ratio_greater_equal<oneThird, half>::value << endl;

	// ratio_less
	cout << "ratio_less: \t \t" << ratio_less<oneThird, half>::value << endl;

	// ratio_less_equal
	cout << "ratio_less_equal: \t" << ratio_less_equal<oneThird, half>::value << endl;

	// ratio_multiply
	typedef ratio_multiply<oneThird, half> mult;
	cout << "ratio_multiply: \t" << mult::num << " / " << mult::den << endl;

	// ratio_not_equal
	cout << "ratio_not_equal: \t" << ratio_not_equal<oneThird, half>::value << endl;

	// ratio_subtract
	typedef ratio_subtract<oneThird, half> sub;
	cout << "sub: \t \t \t" << sub::num << " / " << sub::den << endl;


	return 0;
}
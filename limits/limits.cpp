#include <iostream>
#include <limits>

using namespace std;

int main() {
	cout << "min: \t \t" << numeric_limits<int>::min() << endl;
	cout << "max: \t \t" << numeric_limits<int>::max() << endl;
	cout << "is_signed: \t" << numeric_limits<int>::is_signed << endl;
	cout << "is_integer: \t" << numeric_limits<int>::is_integer << endl;
	cout << "is_exact: \t" << numeric_limits<int>::is_exact << endl;
	cout << "digits: \t" << numeric_limits<int>::digits << endl;
	cout << "digits10: \t" << numeric_limits<int>::digits10 << endl;
	cout << "max_digits10: \t" << numeric_limits<int>::max_digits10 << endl; // Number of digits (in decimal base) required to ensure that values that differ are always differentiated
	cout << "has_infinity: \t" << numeric_limits<int>::has_infinity << endl;
	cout << "radix: \t \t" << numeric_limits<int>::radix << endl;
	cout << "epsilon: \t" << numeric_limits<int>::epsilon() << endl;
	cout << "round_error: \t" << numeric_limits<int>::round_error() << endl;
	cout << "min_exponent: \t" << numeric_limits<int>::min_exponent << endl;
	cout << "min_exponent10: " << numeric_limits<int>::min_exponent10 << endl;
	cout << "max_exponent: \t" << numeric_limits<int>::max_exponent << endl;
	cout << "has_quiet_NaN: \t" << numeric_limits<int>::has_quiet_NaN << endl;
	cout << "has_signaling_NaN: \t" << numeric_limits<int>::has_signaling_NaN << endl;
	cout << "has_denorm: \t" << numeric_limits<int>::has_denorm << endl;
	cout << "has_denorm_loss: \t" << numeric_limits<int>::has_denorm_loss << endl;
	cout << "infinity: \t" << numeric_limits<int>::infinity() << endl;
	cout << "quiet_NaN: \t" << numeric_limits<int>::quiet_NaN() << endl;
	cout << "signaling_NaN: \t" << numeric_limits<int>::signaling_NaN() << endl;
	cout << "denorm_min: \t" << numeric_limits<int>::denorm_min() << endl;
	cout << "is_iec559: \t" << numeric_limits<int>::is_iec559 << endl;
	cout << "is_bounded: \t" << numeric_limits<int>::is_bounded << endl;
	cout << "is_modulo: \t" << numeric_limits<int>::is_modulo << endl;
	cout << "traps: \t" << numeric_limits<int>::traps << endl;
	cout << "tinyness_before:" << numeric_limits<int>::tinyness_before << endl;
	cout << "round_style: \t" << numeric_limits<int>::round_style << endl;

	cout << "lowest: \t" << numeric_limits<float>::lowest() << endl;
}
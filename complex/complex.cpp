#include <iostream>
#include <complex>
#include <cstdlib> 	// Random
#include <ctime> 	// Time
using namespace std;

double random_number(const int a = 10, const int b = 0) {
	return (rand() % a) + b;
}

int main() {
	srand(time(0));

	complex<double> c(random_number(), random_number());
	complex<double> d(4, 6);

	cout << "complex: \t" << c << endl;

	// abs - takes the absolute value (basically the Pythagorean theorem)
	cout << "abs: \t \t" << abs(c) << endl;

	// acos
	cout << "acos: \t \t" << acos(c) << endl;

	// acosh
	cout << "acosh: \t \t" << acosh(c) << endl;

	// arg - returns the phase angle in radiancs
	cout << "arg: \t \t" << arg(c) << endl;

	// asin
	cout << "asin: \t \t" << asin(c) << endl;

	// asinh
	cout << "asinh: \t \t" << asinh(c) << endl;

	// conj 
	cout << "conj: \t \t" << conj(c) << endl;

	// cos
	cout << "cos: \t \t" << cos(c) << endl;

	// cosh
	cout << "cosh: \t \t" << cosh(c) << endl;

	// exp - Returns the base-e exponential of the complex number x
	cout << "exp: \t \t" << exp(c) << endl;

	// imag
	cout << "imag: \t \t" << imag(c) << endl;

	// log - Returns the natural (base-e) logarithm of the complex number x
	cout << "log: \t \t" << log(c) << endl;

	// log10
	cout << "log10: \t \t" << log10(c) << endl;

	// norm
	cout << "norm: \t \t" << norm(c) << endl;

	// polar
	cout << "polar: \t \t" << polar(10.0, 3.14) << endl;

	// pow
	cout << "pow: \t \t" << pow(c, d) << endl;

	// proj
	cout << "proj: \t \t" << proj(c) << endl;

	// real
	cout << "real: \t \t" << real(c) << endl;

	// sin
	cout << "sin: \t \t" << sin(c) << endl;

	// sinh
	cout << "sinh: \t \t" << sinh(c) << endl;

	// sqrt
	cout << "sqrt: \t \t" << sqrt(c) << endl;

	// tan
	cout << "tan: \t \t" << tan(c) << endl;

	// tanh
	cout << "tanh: \t \t" << tanh(c) << endl;

	return 0;
}
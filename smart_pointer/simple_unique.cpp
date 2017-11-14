#include <iostream>
#include <memory>

using namespace std;

int main() {
	unique_ptr<int> a (new int);

	*a = 25;

	//cout << a << endl;
	cout << *a << endl;
	cout << &a << endl;

	int* b = new int;

	*b = 4;
	cout << b << endl;
	cout << *b << endl;
	cout << &b << endl;
	delete b;

	unique_ptr<int> c (new int);
	unique_ptr<int> d (new int);
	*c = 5;
	*d = *c;


	return 0;
}
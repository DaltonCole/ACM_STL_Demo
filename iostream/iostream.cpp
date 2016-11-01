#include <iostream>
using namespace std;

int main() {
	string in;

	cin >> in;

	cout << in << endl;

	cerr << "Error!" << endl; // Prints to stderr

	clog << "LOG!" << endl; // Prints to stderr

	return 0;
}
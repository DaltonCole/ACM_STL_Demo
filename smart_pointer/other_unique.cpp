#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
	unique_ptr<int> a(new int);

	a = 5;

	return 0;
}
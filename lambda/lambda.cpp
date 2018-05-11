#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 100000000

int main() {
	int b = 0;
	auto a = [=](auto i){return b + i;};

	for(int i = 0; i < 5; i++) {
		cout << a(i) << endl;
		b++;
	}

	return 0;
}
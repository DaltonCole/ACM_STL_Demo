#include <iostream>
#include <functional>
#include <unordered_set>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
};

struct myHash {
	size_t operator () (const Point & p) {
		return hash<string>{}(to_string(p.x) + " " + to_string(p.y));
	}
};

int main() {
	unordered_set<Point, myHash> test;

	Point a;
	a.x = 5;
	a.y = 6;
	test.insert(a);
	a.x = 6;
	test.insert(a);
	a.x = 5;
	test.insert(a);

	for(auto i : test) {
		cout << i.x << " " << i.y << endl;
	}

	return 0;
}
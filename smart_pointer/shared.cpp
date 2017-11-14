#include <iostream>
#include <memory>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Other {
	shared_ptr<Point> p;
	int a;
	int b;
};

int main() {
	Point a;
	a.x = 5;
	a.y = 6;

	Other b;
	b.a = 1;
	b.b = 2;
	b.p = shared_ptr<Point> (new Point);
	b.p -> x = 3;
	b.p -> y = 4;

	Other c;
	c.a = 9;
	c.b = 8;
	c.p = b.p;

	cout << b.p -> x << endl;
	cout << b.p -> y << endl;
	cout << c.p -> x << endl;
	cout << c.p -> y << endl << endl;

	c.p -> x = 990;

	cout << b.p -> x << endl;
	cout << b.p -> y << endl;
	cout << c.p -> x << endl;
	cout << c.p -> y << endl << endl;


	return 0;
}
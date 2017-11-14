#include <iostream>
#include <memory>
using namespace std;

struct Point {
	int x;
	int y;
	unique_ptr<int> a;
	unique_ptr<int> b;
};

struct Other {
	int x;
	int y;
	int* a;
	int* b;
};

int main() {
	/* Does not work
	Point c;

	c.x = 5;
	c.y = 6;
	c.a = &c.x;
	c.b = &c.y;
	*/
	Point e;
	e.x = 8;
	e.y = 4;
	e.a = unique_ptr<int> (new int (5));
	e.b = unique_ptr<int> (new int (6));
	cout << e.x << " " << e.y << " " << *e.a << " " << *e.b << endl;

	Other d;
	d.x = 1;
	d.y = 2;
	d.a = &d.x;
	d.b = &d.y;
	cout << d.x << " " << d.y << " " << *d.a << " " << *d.b << endl;

	return 0;
}